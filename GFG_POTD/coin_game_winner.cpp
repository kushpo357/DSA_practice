//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findWinner(int n, int x, int y) {
        // code here
        int val = 1;
        
        vector<int> dp(n, 0);
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            dp[i] = (dp[i + 1] + 1)%2;
            
            if(i + x < n && (dp[i + x] + 1)%2 == 1)
                dp[i] =  1;
            
            if(i + y < n && (dp[i + y] + 1)%2 == 1)
                dp[i] = 1;
                
            cout<<dp[i]<<' ';
        }
        cout<<endl;
        return dp[0];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends
