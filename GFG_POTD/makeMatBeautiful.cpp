//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int>> mat, int n)
    {
        // code here 
        vector<int> rowsum(n, 0);
        vector<int> colsum(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                rowsum[i] += mat[i][j];
                colsum[j] += mat[i][j];
            }
        }
        
        int maxi = 0;
        
        for(int i = 0; i < n; i++) 
            maxi = max(maxi, max(rowsum[i], colsum[i]));
            
        for(int i = 0; i < n; i++)
        {
            rowsum[i] = maxi - rowsum[i];
            colsum[i] = maxi - colsum[i];
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int mini = min(rowsum[i], colsum[j]);
                ans += mini;
                rowsum[i] -= mini;
                colsum[j] -= mini;
            }
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends
