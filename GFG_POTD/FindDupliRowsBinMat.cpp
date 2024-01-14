//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
    public:
    
    struct Node{
      
      struct Node* zero;
      struct Node* one;
      bool isend;
      
      Node()
      {
          zero = NULL;
          one = NULL;
          isend = false;
      }
    };
    
    void isPresent(Node* root, vector<vector<int>> &mat, int i, int j, int n, vector<int> &ans)
    {
        if(j == n)
        {
            if(root->isend == true)
            {
                ans.push_back(i);
            }
            
            root->isend = true;
            return;
        }
        if(mat[i][j] == 0)
        {
            if(root->zero == NULL)
            {
                root->zero = new Node();
            }
            isPresent(root->zero, mat, i, j + 1, n, ans);
        }
        else
        {
            if(root->one == NULL)
            {
                root->one = new Node();
            }
            isPresent(root->one, mat, i, j + 1, n, ans);
        }
    }
    vector<int> repeatedRows(vector<vector<int>> &mat, int m, int n) 
    { 
        // Your code here
        
        Node* root = new Node();
        vector<int> ans;
        for(int i = 0; i < m; i++)
        {
            isPresent(root, mat, i, 0, n, ans);
        }
        
        return ans;
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends
