//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int CountWays(string s){
		    // Code here
		    int n = s.size(), dp[n + 1];
            memset(dp, 0, sizeof dp);
            dp[0] = 1;
            for (int i = 0; i < n; i++)
            {
                int v = (s[i] - '0');
                if (v) dp[i + 1] = dp[i];
                if (i)
                {
                  v = (s[i - 1] - '0') *10 + (s[i] - '0');
                  if (v >= 10 && v <= 26) 
                  dp[i+1] = (dp[i+1] + dp[i-1]) % ((int)1e9+7);
                }
            }
            return dp[n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends