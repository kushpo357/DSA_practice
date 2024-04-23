//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:

    #define MOD 1000000007
    int ways(int x, int y)
    {
        //code here.
        
        vector<vector<int>> dp(x + 1, vector<int> (y + 1, 1));
        
        for(int i = 1; i <= x; i++)
        {
            for(int j = 1; j <= y; j++)
            {
                dp[i][j] = (dp[i - 1][j] % MOD + dp[i][j - 1] % MOD) % MOD;
            }
        }
        
        return dp[x][y];
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends
