//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    int solve(int i, int j, int a[], vector<vector<int>> &dp){
        
        if (i > j)
         return 0;
         
         if (dp[i][j] != -1)
          return dp[i][j];
          
         int x = a[i] + min (solve (i + 2, j, a, dp), solve (i + 1, j - 1, a, dp));
         int y = a[j] + min (solve (i, j - 2, a, dp), solve (i + 1, j - 1, a, dp));
         
         return dp[i][j] = max (x,y);
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, n - 1 , arr, dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends
