//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int child_sum(Node *root)
    {
        if(root==NULL) return 0;
        if(root->left && root->right)
            return root->data + min(child_sum(root->left), child_sum(root->right));
        else if(root->left)
            return root->data + child_sum(root->left);
        else if(root->right)
            return root->data + child_sum(root->right);
        else
            return root->data;
    }
    
    int f(Node *root, int target, int sum)
    {
        if(root == NULL) return -1;
        
        if(root->data == target)
        {
            int minn = child_sum(root) - root->data;
            return sum - minn;
        }
        
        if(root->data > target)
            return f(root->left, target, sum + root->data);
        else return f(root->right, target, sum + root->data);
    }
    
        int maxDifferenceBST(Node *root,int target){
            // Code here
            return f(root,target,0);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends