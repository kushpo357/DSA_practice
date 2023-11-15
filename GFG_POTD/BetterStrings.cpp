//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    #define MOD 1000000007
    int countSubsequence(string s)
    {
        int n = s.size();
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        unordered_map<char, int> lastInd;

        for (int i = 1; i <= n; ++i) 
        {
            dp[i] = (2 * dp[i - 1]) % MOD;
            if (lastInd.find(s[i - 1]) != lastInd.end()) 
            {
                dp[i] = (dp[i] - dp[lastInd[s[i - 1]] - 1] + MOD) % MOD;
            }
            
            lastInd[s[i - 1]] = i;
        }

        return dp[n];
    }

    string betterString(string str1, string str2) {
        // code here
        
        if (countSubsequence(str1) >= countSubsequence(str2))
            return str1;
            
        return str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends
