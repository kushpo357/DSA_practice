//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    struct Node
    {
        struct Node* zero, *one;
        bool end;
    };
    
    struct Node* getnode()
    {
        struct Node* newnode = new Node;
        newnode->zero = NULL;
        newnode->one = NULL;
        newnode->end = false;
    }
    
    void makebintree(struct Node* root, vector<int> &v, vector<vector<int>> &ans)
    {
        struct Node* curr = root;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i])
            {
                if(curr->one == NULL)
                    curr->one = getnode();
                
                curr = curr->one;
            }
            else
            {
                if(curr->zero == NULL)
                    curr->zero = getnode();
                
                curr = curr->zero;
            }
        }
        if(curr->end == false)
        {
            curr->end = true;
            ans.push_back(v);
        }
    }
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        //Your code here
        struct Node* root = getnode();
        vector<vector<int>> ans;
        for(int i = 0; i < row; i++)
        {
            struct Node* temp = root;
            vector<int> v(M[i], M[i] + col);
            makebintree(temp, v, ans);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends