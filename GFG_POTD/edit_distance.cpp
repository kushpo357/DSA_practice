//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int editDistance(string str1, string str2) {
        //code here
        
        int n1 = str1.size(), n2 = str2.size();
        
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, 0));
        
        for(int i = 0; i <= n1; i++)
        {
            dp[i][0] = i;
        }
        for(int j = 0; j <= n2; j++) 
        {
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= n1; i++)
        {
            for(int j = 1; j <= n2; j++)
            {
                if(str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
                }
            }
        }
        
        return dp[n1][n2];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
