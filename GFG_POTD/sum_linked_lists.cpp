//{ Driver Code Starts
// driver

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

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    
    void countNodes(struct Node* root, int & count)
    {
        if(root == NULL) return;
        
        count++;
        
        countNodes(root->next, count);
    }
    
    struct Node* rev(struct Node* root, struct Node* revhead)
    {
        if(root == NULL) return revhead;
        struct Node* temp = root->next;
        root->next = revhead;
        revhead = root;
        return rev(temp, revhead);
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2) {
        int count1 = 0, count2 = 0;
        
        countNodes(num1, count1);
        countNodes(num2, count2);
        
        while(count1 > count2) {
            struct Node* newNode = new Node(0);
            newNode->next = num2;
            num2 = newNode;
            count2++;
        }
        while(count2 > count1) {
            struct Node* newNode = new Node(0);
            newNode->next = num1;
            num1 = newNode;
            count1++;
        }
        
        struct Node* revhead1 = NULL, *revhead2 = NULL;
        num1 = rev(num1, revhead1);
        num2 = rev(num2, revhead2);
        
        struct Node* ansNode = new Node(0);
        struct Node* curr = ansNode;
        struct Node* curr1 = num1;
        struct Node* curr2 = num2;
        int carry = 0;
    
        while (curr1 != NULL || curr2 != NULL || carry) {
            int val = carry + (curr1 ? curr1->data : 0) + (curr2 ? curr2->data : 0);
            carry = val / 10;
            val = val % 10;
            curr->data = val;
            
            if (curr1) curr1 = curr1->next;
            if (curr2) curr2 = curr2->next;
            
            
            if (curr1 != NULL || curr2 != NULL || carry) {
                curr->next = new Node(0);
                curr = curr->next;
            }
        }
        struct Node* revhead3 = NULL;
        ansNode = rev(ansNode, revhead3);
        while (ansNode && ansNode->data == 0) {
            struct Node* temp = ansNode;
            ansNode = ansNode->next;
            delete(temp);
        }
        
        return ansNode ? ansNode : new Node(0);
    }

};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
