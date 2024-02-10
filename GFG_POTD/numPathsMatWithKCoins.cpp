//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    long long func(vector<vector<int>> &arr, int i, int j, int k, int &n, vector<vector<vector<int>>> &dp){
        if(i == n-1 and j == n-1) return k == arr[i][j];
        if(i < 0 or j < 0 or i >= n or j >= n or k <= 0) return 0;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        return dp[i][j][k] = func(arr, i, j+1, k - arr[i][j], n, dp) + func(arr, i+1, j, k - arr[i][j], n, dp);
    }
public:
    long long numberOfPath(int n, int k, vector<vector<int>> arr){ 
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1, -1)));
        return func(arr, 0, 0, k, n, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends
