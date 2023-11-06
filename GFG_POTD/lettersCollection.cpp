//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void addSum(vector<vector<int>> &mat, int n, int m, int &sum, int i, int j)
    {
        if(i >= 0 && j >= 0 && i < n && j < m)
            sum += mat[i][j];
    }
    int solveQ1(vector<vector<int>> &mat, int n, int m, int i, int j)
    {
        int sum = 0;
        
        addSum(mat, n, m, sum, i - 1, j - 1);
        addSum(mat, n, m, sum, i + 1, j - 1);
        addSum(mat, n, m, sum, i - 1, j + 1);
        addSum(mat, n, m, sum, i + 1, j + 1);
        addSum(mat, n, m, sum, i, j - 1);
        addSum(mat, n, m, sum, i - 1, j);
        addSum(mat, n, m, sum, i + 1, j);
        addSum(mat, n, m, sum, i, j + 1);
        
        return sum;
    }
    int solveQ2(vector<vector<int>> &mat, int n, int m, int i, int j)
    {
        int sum = 0;
        
        addSum(mat, n, m, sum, i - 1, j - 2);
        addSum(mat, n, m, sum, i - 2, j - 1);
        addSum(mat, n, m, sum, i + 1, j - 2);
        addSum(mat, n, m, sum, i + 2, j - 1);
        addSum(mat, n, m, sum, i - 1, j + 2);
        addSum(mat, n, m, sum, i - 2, j + 1);
        addSum(mat, n, m, sum, i + 2, j + 1);
        addSum(mat, n, m, sum, i + 1, j + 2);
        addSum(mat, n, m, sum, i + 2, j + 2);
        addSum(mat, n, m, sum, i + 2, j - 2);
        addSum(mat, n, m, sum, i - 2, j + 2);
        addSum(mat, n, m, sum, i - 2, j - 2);
        addSum(mat, n, m, sum, i, j - 2);
        addSum(mat, n, m, sum, i - 2, j);
        addSum(mat, n, m, sum, i + 2, j);
        addSum(mat, n, m, sum, i, j + 2);
        
        return sum;
    }
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        // code here
        
        vector<int> ans;
        for(int i = 0; i < q; i++)
        {
            if(queries[i][0] == 1)
            {
                ans.push_back(solveQ1(mat, n, m, queries[i][1], queries[i][2]));
            }
            else
            {
                ans.push_back(solveQ2(mat, n, m, queries[i][1], queries[i][2]));
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>q;
        vector<int> queries[q];
        for(int k = 0;k < q;k++){
            cin>>ty>>i>>j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends
