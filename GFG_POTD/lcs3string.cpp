//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:

        int solve(string &a, string &b, string &c, const int &n1, const int &n2, const int &n3, int i, int j, int k,
        vector<vector<vector<int>>> &dp)
        {
            if(i >= n1 || j >= n2 || k >= n3) return 0;
            if(dp[i][j][k] != -1) return dp[i][j][k];
            if(a[i] == b[j] && b[j] == c[k]) return dp[i][j][k] = 1 + solve(a, b, c, n1, n2, n3, i + 1, j + 1, k + 1, dp);
            int ans = 0;
            if(a[i] == b[j]) ans = max(solve(a, b, c, n1, n2, n3, i + 1, j + 1, k, dp), ans); 
            if(a[i] == c[k]) ans = max(solve(a, b, c, n1, n2, n3, i + 1, j, k + 1, dp), ans); 
            if(c[k] == b[j]) ans = max(solve(a, b, c, n1, n2, n3, i, j + 1, k + 1, dp), ans);
            ans = max(ans, solve(a, b, c, n1, n2, n3, i + 1, j, k, dp));
            ans = max(ans, solve(a, b, c, n1, n2, n3, i, j + 1, k, dp));
            ans = max(ans, solve(a, b, c, n1, n2, n3, i, j, k + 1, dp));
            
            return dp[i][j][k] = ans;
        }
        int LCSof3 (string a, string b, string c, int n1, int n2, int n3)
        {
            // your code here
            
            vector<vector<vector<int>>> dp(n1, vector<vector<int>>(n2, vector<int>(n3, -1)));
            int ans = 0;
            
            ans = solve(a, b, c, n1, n2, n3, 0, 0, 0, dp);
            
            return ans;
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
