//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	    // Your code goes here
	    
	    vector<vector<int>> dp(m, vector<int> (n, 0));
	    
	    dp[m - 1][n - 1] = points[m - 1][n - 1];
	    
        if(dp[m - 1][n - 1] > 1) dp[m - 1][n - 1] = 0;
	    for(int i = m - 2; i >= 0; i--)
	    {
	        dp[i][n - 1] = dp[i + 1][n - 1] + points[i][n - 1];
	        if(dp[i][n - 1] > 1) dp[i][n - 1] = 0;
	    }
	    
	    for(int i = n - 2; i >= 0; i--)
	    {
	        dp[m - 1][i] = dp[m - 1][i + 1] + points[m - 1][i];
	        if(dp[m - 1][i] > 1) dp[m- 1][i] = 0;
	    }
	    
	    for(int i = m - 2; i >= 0; i--)
	    {
	        for(int j = n - 2; j >= 0; j--)
	        {
	            dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]) + points[i][j];
	            if(dp[i][j] > 0) dp[i][j] = 0;
	            //cout<<dp[i][j]<<' ';
	        }
	        //cout<<endl;
	    }
	    
	    if(dp[0][0] < 1) return 1 + abs(dp[0][0]);
	    return dp[0][0];
	} 
};



//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
