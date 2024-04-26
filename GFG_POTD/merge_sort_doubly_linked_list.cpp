//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    
    struct Node* FindMid(struct Node* head)
    {
        struct Node* mid = head;
        struct Node* curr = head;
        
        while(curr->next && curr->next->next)
        {
            mid = mid->next;
            curr = curr->next->next;
        }
        
        return mid->next;
    }
    
    struct Node* merge(struct Node* left, struct Node* right)
    {
        struct Node* root = NULL;
        
        if(left->data <= right->data)
        {
            root = left;
            left = left->next;
        }
        else
        {
            root = right;
            right = right->next;
        }
        
        struct Node* curr = root;
        while(left && right)
        {
            if(left->data <= right->data)
            {
                curr->next = left;
                left = left->next;
            }
            else
            {
                curr->next = right;
                right = right->next;
            }
            curr->next->prev = curr;
            curr = curr->next;
        }
        
        while(left)
        {
            curr->next = left;
            left->prev = curr;
            left = left->next;
            curr = curr->next;
        }
        while(right)
        {
            curr->next = right;
            right->prev = curr;
            right = right->next;
            curr = curr->next;
        }
        
        return root;
    }
    
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        
        if(head->next == NULL) return head;
        
        struct Node* mid = FindMid(head);
        
        mid->prev->next = NULL;
        mid->prev = NULL;
        
        head = sortDoubly(head);
        
        mid = sortDoubly(mid);
        
        head = merge(head, mid);
        
        return head;
        
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends
