//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

// struct Node
// {
// 	int data;
// 	struct Node *next;
	
// 	Node(int x){
// 	    data =x;
// 	    next = NULL;
// 	}
// };

class Solution
{
public:
    Node* sortasc(Node* curr, Node** root)
    {
        if(curr->next == NULL)
        {
            (*root) = curr;
            return curr;
        }
        
        Node* temp = sortasc(curr->next, root);
        temp->next = curr;
        curr->next = NULL;
        
        return curr;
    }

    void sort(Node **head)
    {
        // Code here
        if ((*head) == NULL || (*head)->next == NULL)
            return;

        Node *second = (*head)->next;
        Node *curr = *head;
        Node *seccurr = second;
        
        while (curr && seccurr)
        {
            if (curr->next)
            {
                curr->next = seccurr->next;
                curr = curr->next;
                if (seccurr->next)
                    seccurr->next = curr->next;
                seccurr = seccurr->next;
            }
        }
        
        curr = *head;
        
        while(curr->next) curr = curr->next;
        
        // cout<<curr->data<<endl;
        Node* root = NULL;
        sortasc(second, &root);
        curr->next = root;
    }
};


//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends
