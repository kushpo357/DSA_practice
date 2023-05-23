//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
        int pres = 0, pree = size - 1, preMs = 0, preMe = size - 1;
        Node *head = makebintree(pre, preMirror, size, pres, pree, preMs, preMe);
        
        return head;
    }
    
    Node* makebintree(int pre[], int preMirror[], int size, int pres, int pree, int preMs, int preMe)
    {
        if(pres > pree || preMs > preMe) return NULL;
        
        Node* root = new Node(pre[pres]);
        
        if(pres == pree || preMs == preMe) return root;
        
        pres++;
        preMs++;
        
        int prelen = 0, preMlen = 0;
        for(int i = pres; i < size; i++)
        {
            if(pre[i] == preMirror[preMs]) break;
            prelen++;
        }
        for(int i = preMs; i < size; i++)
        {
            if(preMirror[i] == pre[pres]) break;
            preMlen++;
        }
        
        root->left = makebintree(pre, preMirror, size, pres, pres + prelen - 1, preMs + preMlen, preMe);
        root->right = makebintree(pre, preMirror, size, pres + prelen, pree, preMs, preMs + preMlen - 1);
        
        return root;
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends