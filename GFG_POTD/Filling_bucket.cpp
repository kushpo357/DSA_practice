//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fillingBucket(int N) {
        // code here
        int mod = 1e8;
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(2);
        for(int i = 2; i < N; i++)
            dp.push_back((dp[i - 1] + dp[i - 2])%mod);
        return dp[N - 1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends