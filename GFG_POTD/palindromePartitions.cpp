//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPal(string &str, int s, int e)
    {
        while(s < e)
        {
            if(str[s] != str[e]) return 0;
            s++;
            e--;
        }
        
        return 1;
    }
    int solve(string & str, int s, int e, int n, vector<vector<int>> & dp)
    {
        int minpart = INT_MAX;
        if(s > e) return dp[s][e] = 0;
        if(s == e) return dp[s][e] = 1;
        for(int i = e; i >= s; i--)
        {
            if(isPal(str, s, i))
            {
                int temp;
                if(dp[i + 1][e] == -1)
                {
                    dp[i + 1][e] = solve(str, i + 1, e, n , dp);
                }
                
                temp = 1 + dp[i + 1][e];
                minpart = min(minpart,temp);
            }
        }
        
        return minpart;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1 , -1));
        return solve(str, 0, n - 1, n, dp) - 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
