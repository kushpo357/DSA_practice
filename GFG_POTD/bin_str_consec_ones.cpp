//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    #define MOD 1000000007
    
    int numberOfConsecutiveOnes(int n) {
        // code here
        
        
        if(n == 1) return 0;
        if(n == 2) return 1;
        vector<long long> power(n, 0);
        
        vector<long long> dp(n, 0);
        
        power[0] = 2;
        power[1] = 4;
        dp[0] = 0;
        dp[1] = 1;
        
        for(long long i = 2; i < n; i++)
        {
            dp[i] = power[i - 2];
            dp[i] = (dp[i]%MOD + dp[i - 2]%MOD + dp[i - 1] %MOD)%MOD;
            power[i - 1] = (power[i - 2]%MOD + power[i - 2]%MOD)%MOD;
            power[i - 1] = (power[i - 2]*2)%MOD;
        }
        
        return dp[n - 1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends
