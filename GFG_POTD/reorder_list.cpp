//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
    void reorderList(Node* head) {
        // Your code here
        
        if(head->next == NULL)
            return;
        
        if(head->next->next == NULL)
            return;
            
        Node* mid = FindMid(head);
        
        Node* dist = mid;
        mid = reverse(mid->next);
        
        dist->next = NULL;
        
        Node* root = head;
        
        while(mid != NULL)
        {
            Node* temp = root->next;
            root->next = mid;
            root = temp;
            temp = mid->next;
            mid->next = root;
            mid = temp;
        }
    }
    Node* FindMid(Node* root)
    {
        Node* fast = root, *slow = root;
        
        while(fast->next != NULL)
        {
            Node*temp = fast->next;
            if(temp->next == NULL )
                return slow;
            fast = temp->next;
            slow = slow->next;
        }
        
        return slow;
    }
    Node* reverse(Node* root)
    {
        Node* curr = root->next;
        root->next = NULL;
        
        while(curr != NULL)
        {
            Node* temp = curr;
            curr = curr->next;
            temp->next = root;
            root = temp;
        }
        
        return root;
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends