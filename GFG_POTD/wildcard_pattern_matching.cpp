//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    
    bool solve(int i, int j, string &pat, string &str, const int &n, const int &m, vector<vector<int>> &dp)
    {
        if(i == n && j == m) return true;
        if(i == n) return false;
        if(j == m)
        {
            while (i < n && pat[i] == '*') i++;
            return i == n;
        }
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        if(isalnum(pat[i]))
        {
            if(pat[i] == str[j])
                return dp[i][j] = solve(i + 1, j + 1, pat, str, n, m, dp);
            
            return dp[i][j] = false;
        }
        
        if(pat[i] == '?')
            return dp[i][j] = solve(i + 1, j + 1, pat, str, n, m, dp);
            
        bool ans = false;
        
        for(int k = j; k <= m; k++)
        {
            ans = ans || solve(i + 1, k, pat, str, n, m, dp);
        }
        
        return dp[i][j] = ans;
    }
    int wildCard(string pat, string str) {
        // code here
        
        int n = pat.size(), m = str.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(0, 0, pat, str, n, m, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends
