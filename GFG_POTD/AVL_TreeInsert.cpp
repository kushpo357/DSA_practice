//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution {
public:
    Node* rl(Node* p) {
        Node* rchildp = p->right;
        Node* lchild_rchildp = rchildp->left;
        Node* lchild_lchild_rchildp = lchild_rchildp->left;
        Node* rchild_lchild_rchildp = lchild_rchildp->right;
        lchild_rchildp->left = p;
        lchild_rchildp->right = rchildp;
        rchildp->left = rchild_lchild_rchildp;
        p->right = lchild_lchild_rchildp;
        return lchild_rchildp;
    }

    Node* rr(Node* p) {
        Node* lchildp = p->left;
        Node* rchild_lchildp = lchildp->right;
        lchildp->right = p;
        p->left = rchild_lchildp;
        return lchildp;
    }

    Node* ll(Node* p) {
        Node* rchildp = p->right;
        Node* lchild_rchildp = rchildp->left;
        rchildp->left = p;
        p->right = lchild_rchildp;
        return rchildp;
    }

    Node* lr(Node* p) {
        Node* lchildp = p->left;
        Node* rchild_lchildp = lchildp->right;
        Node* lchild_rchild_lchildp = rchild_lchildp->left;
        Node* rchild_rchild_lchildp = rchild_lchildp->right;
        rchild_lchildp->left = lchildp;
        lchildp->right = lchild_rchild_lchildp;
        rchild_lchildp->right = p;
        p->left = rchild_rchild_lchildp;
        return rchild_lchildp;
    }

    int height(Node* p) {
        return (p == NULL) ? 0 : 1 + max(height(p->left), height(p->right));
    }

    int balanceFactor(Node* p) {
        return height(p->left) - height(p->right);
    }

    Node* insertToAVL(Node* node, int data) {
        if (node == NULL) {
            Node* nn = new Node(data);
            return nn;
        }

        if (node->data < data) {
            node->right = insertToAVL(node->right, data);
        } else {
            node->left = insertToAVL(node->left, data);
        }

        int bfn = balanceFactor(node);
        int bfnl = (bfn == 2) ? balanceFactor(node->left) : 0;
        int bfnr = (bfn == -2) ? balanceFactor(node->right) : 0;

        if (bfn == 2 && bfnl == 1) {
            return rr(node);
        }
        if (bfn == 2 && bfnl == -1) {
            return lr(node);
        }
        if (bfn == -2 && bfnr == -1) {
            return ll(node);
        }
        if (bfn == -2 && bfnr == 1) {
            return rl(node);
        }

        return node;
    }
};





//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}
// } Driver Code Ends
