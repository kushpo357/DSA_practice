//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    
    int checkHeight(Node* root)
    {
        if(root == NULL)
            return 0;
        
        int h = checkHeight(root->left);
        h = max(h, checkHeight(root->right));
        
        return h + 1;
    }
    int targetDis(Node* root, const int &target, int &maxBurn)
    {
        if(root == NULL)
            return -1;
        
        if(root->data == target)
        {
            maxBurn = checkHeight(root->left);
            maxBurn = max(checkHeight(root->right), maxBurn);
            return 1;
        }
        
        int dis = targetDis(root->left, target, maxBurn);
        
        if(dis != -1)
        {
            maxBurn = max(maxBurn, dis + checkHeight(root->right));
            return dis + 1;
        }
        
        dis = targetDis(root->right, target, maxBurn);
        
        if(dis != -1)
        {
            maxBurn = max(maxBurn, dis + checkHeight(root->left));
            return dis + 1;
        }
        
        return -1;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        int maxBurn = -1;
        
        targetDis(root, target, maxBurn);
        
        return maxBurn;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
