//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    
    int help(int ind, int n,int total, vector<int> &cost,  vector<vector<int>> &dp){
        if(ind==n) return 0;
        if(dp[ind][total]!=-1) return dp[ind][total];
        if(total < cost[ind]){
            return dp[ind][total] = help(ind+1,n, total, cost,dp);
        }
        else{
            int leftAmount = total - cost[ind];
            int refund = cost[ind]*0.9;
            leftAmount += refund;
            
            int pick = 1 + help(ind+1,n, leftAmount, cost,dp);
            int notPick = help(ind+1,n, total, cost,dp);
            return dp[ind][total] = max(pick, notPick);
        }
    }
    
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dp(n+1, vector<int>(total+1, -1));
        return help(0,n,total,cost, dp);
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
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends
