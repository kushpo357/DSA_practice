//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
  
  #define MOD 1000000007
  
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	   
	   int n = s.size();
        
        vector<int> lastOccur(26, -1); 
        vector<int> dp(n + 1, 0); 
        
        dp[0] = 1; 
        
        for (int i = 1; i <= n; i++)
        {
            dp[i] = (2 * dp[i - 1]) % MOD;
            
            if (lastOccur[s[i - 1] - 'a'] != -1)
                dp[i] = (dp[i] - dp[lastOccur[s[i - 1] - 'a']]) % MOD;
                
            lastOccur[s[i - 1] - 'a'] = i - 1; 
        }
        
        
        if (dp[n] < 0) dp[n] += MOD;
        
        return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends
