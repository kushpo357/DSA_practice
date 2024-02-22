//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

#define MOD 1000000007 
class Solution
{
    public:
    
    int subsequenceCount(string s, string t)
    {
      //Your code here
      
      int n = s.size(), m = t.size();
      
      vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
        for (int i = 0; i <= n; i++)
            dp[i][m] = 1;
    
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (s[j] == t[i]) 
                    dp[j][i] = dp[j + 1][i + 1] % MOD;
    
                dp[j][i] = (dp[j][i] % MOD + dp[j + 1][i] % MOD) % MOD;
            }
        }
    
        return dp[0][0];
    }
};
 



//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends
