//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	#define MOD 1000000007
    int solve(int arr[], int n, int sum, int i, vector<vector<int>> &dp )
    {
        if(sum<0) return 0;
        
        if(i >= n)
        {
            if(sum == 0) return 1;
            
            return 0;
        }
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int ans = 0;
        
        ans=(solve(arr, n, sum - arr[i], i + 1, dp) % MOD + solve(arr, n, sum, i + 1, dp) % MOD) % MOD;
       
       return dp[i][sum]=ans;
       
    }
     
    int perfectSum(int arr[], int n, int sum)
    { 
       vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
       return solve(arr, n, sum, 0, dp);
    }
    
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
