//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    #define ll long long
    #define MOD 1000000007
    int countWays(string s1, string s2) {
        // code here
        
        ll n = s1.size(), m = s2.size();
        
        vector<vector<ll>> dp(n + 1, vector<ll> (m + 1, 0));
        
        for(int i = 0; i <= n; i++)
            dp[i][m] = 1;
            
            
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                if(s1[i] == s2[j])
                {
                    dp[i][j] = dp[i + 1][j + 1]%MOD;
                }
                
                dp[i][j] = (dp[i][j]%MOD + dp[i + 1][j]%MOD)%MOD;
            }
        }
        return dp[0][0];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends
