//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxCoins(int n, vector<int> &arr) {
        // code here
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        return solve(arr, 0, n - 1, dp);
    }
    
    int solve(vector<int> &a, int i, int j, vector<vector<int>> &dp)
    {
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int l1 = (i - 1 >= 0 ? a[i - 1]: 1);
        int r1 = (j + 1 < a.size() ? a[j + 1] : 1);
        int ans = 0;
        
        for(int k = i; k <= j; k++)
        {
            int left = solve(a, i, k - 1, dp);
            int right = solve(a, k + 1, j, dp);
            
            int coin = left + right + l1*a[k]*r1;
            
            ans = max(ans, coin);
        }
        
        return dp[i][j] = ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends