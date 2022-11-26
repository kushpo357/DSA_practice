//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    int ind = 0;
    Node *treeFromString(string str){
        // code here
        Node* root = new Node(num(str));
        makeTree(root, str);
        return root;
    }
    
    int num(string str)
    {
        int ans = 0;
        
        while(str[ind]>= '0' && str[ind] <= '9')
        {
            ans = ans*10 + str[ind] - 48;
            ind++;
        }    
        return ans;
    }
    
    void makeTree(Node* root, string str)
    {
        if(str[ind] == '\0')
            return;
            
        if(str[ind] == ')')
        {
            ind++;
            return;
        }
            
        if(str[ind] == '(')
        {
            ind++;
            root->left = new Node(num(str));
            makeTree(root->left, str);
        }
        
        if(str[ind] == '\0')
            return;
            
        if(str[ind] == ')')
        {
            ind++;
            return;
        }
        
        if(str[ind] == '(')
        {
            ind++;
            root->right = new Node(num(str));
            makeTree(root->right, str);
        }
        
        if(str[ind] == ')')
            ind++;
        
        return;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends