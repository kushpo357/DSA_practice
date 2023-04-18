//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int ans=INT_MAX;
    pair<pair<int,int>,pair<int,int>> f(Node *root,int target)
    {
        if(!root)
        {
            return {{INT_MAX,INT_MIN},{0,0}};
        }
        auto left = f(root->left,target);
        auto right = f(root->right,target);
        if(root->data>left.first.second&&root->data<right.first.first)
        {
            if((left.second.second+right.second.second+root->data)==target) ans = min(ans,left.second.first+right.second.first+1);
            int curmin = min(root->data,min(left.first.first,right.first.first));
            int curmax = max(root->data,max(left.first.second,right.first.second));
            return {{curmin,curmax},{left.second.first+right.second.first+1,(left.second.second+right.second.second+root->data)}};
        }
        else return {{INT_MIN,INT_MAX},{0,0}};
    }
    int minSubtreeSumBST(int target, Node *root) {
        auto it = f(root,target);
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends