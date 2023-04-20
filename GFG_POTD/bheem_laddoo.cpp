//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    int k;
    int target;
    void solve(Node* root, int &dis, int &ans)
    {
        if(root->data == target)
        {
            downsum(root, k + 1, ans);
            dis = k;
            return;
        }
        
        if(root->left) solve(root->left, dis, ans);
        if(dis  > 0) 
        {
            ans += root->data;
            if(root->right) downsum(root->right, dis - 1, ans);
            dis--;
            return;
        }
        
        if(root->right) solve(root->right, dis, ans);
        if(dis > 0) 
        {
            ans += root->data;
            if(root->left) downsum(root->left, dis - 1, ans);
            dis--;
            return;
        }
        
    }
    void downsum(Node* curr, int dis, int &ans)
    {
        if(dis <= 0) return;
        else
        {
            ans += curr->data;
            if(curr->left) downsum(curr->left, dis - 1, ans);
            if(curr->right) downsum(curr->right, dis - 1, ans);
        }
    }
    int ladoos(Node* root, int home, int K)
    {
        // Your code goes here
        k = K;
        target = home;
        int dis = 0;
        int ans = 0;
        solve(root, dis, ans);
        return ans;
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends