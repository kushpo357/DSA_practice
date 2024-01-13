//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    
    Node* sort(Node* root)
    {
        if(root == NULL) return root;
        
        root->next = sort(root->next);
        
        if(root->next != NULL && root->data > root->next->data)
        {
            Node* temp = root;
            Node* curr = root;
            root = root->next;
            while(curr->next != NULL && temp->data > curr->next->data)
            {
                curr = curr->next;
            }
            
            temp->next = curr->next;
            curr->next = temp;
        }
        
        return root;
    }
    Node* insertionSort(struct Node* head)
    {
        //code here
        Node* temp = new Node(-1);
        temp->next = head;
        sort(temp);
        
        return temp->next;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends
