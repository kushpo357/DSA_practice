//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    private:
    
    #define MOD 1000000007
    
    int solve(int i, int n, int &x, int dp[1001][1001])
    {
        if(n == 0) return 1;
        if(i > n) return 0;
        
        if(dp[i][n] != -1) return dp[i][n];
        
        int notTake = solve(i + 1, n, x, dp);
        int take = 0;
        
        if(n - pow(i, x) >= 0) 
            take = solve(i + 1,  n - pow(i, x), x, dp);
        
        return dp[i][n] = (take + notTake) % MOD;
    }

    public:
    int numOfWays(int n, int x) {
        //code here
        
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return solve(1, n, x, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends