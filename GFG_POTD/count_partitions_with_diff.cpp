//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int mod = 1e9+7;
        
        int range = 0;
        for(int i=0;i<n;i++) range += arr[i]%mod;
        
        if(range-d < 0 || ((d+range) % 2)) return 0;
        
        int sum = ((range+d)/2);
        
        vector<vector<int>> dp(n+1, vector<int>(sum+1));
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0) dp[i][j] = 0; 
                if(j==0) dp[i][j] = 1; 
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1] <= j){
                    
                    dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j])%mod;
                }
                else{
                    
                    dp[i][j] = dp[i-1][j]%mod;
                }
            }
        }
        return dp[n][sum]%mod; 
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
