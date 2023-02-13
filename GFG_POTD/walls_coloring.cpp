//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int n) 
    {
        // Write your code here.
        vector<vector<int>> dp(n, vector<int> (3, 0));
        
        dp[0][0] = colors[0][0];
        dp[0][1] = colors[0][1];
        dp[0][2] = colors[0][2];
        
        for(int i = 1; i < n; i++)
        {
            dp[i][0] = colors[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = colors[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = colors[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
        }
        return min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends