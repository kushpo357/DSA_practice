//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function to Build Tree
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

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//Back-end complete function Template for C++
class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    
    void find(Node* root, int &mindist, int &maxdist, int &dist)
    {
        if(root == NULL)
        {
            return;
        }
        
        mindist = min(mindist, dist);
        maxdist = max(maxdist, dist);
        
        if(root->left)
        {
            find(root->left, mindist, maxdist, --dist);
            dist++;
        }
        if(root->right)
        {
            find(root->right, mindist, maxdist, ++dist);
            dist--;
        }
    }
    int verticalWidth(Node* root) {
        // code here
        
        if(root == NULL) return 0;
        
        int mindist = 0;
        int maxdist = 0;
        
        int dist = 0;
        
        find(root, mindist, maxdist, dist);
        
        return maxdist - mindist + 1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        Solution obj;
        Node *root = buildTree(str);

        cout << obj.verticalWidth(root) << "\n";
    }

    return 0;
}

// } Driver Code Ends
