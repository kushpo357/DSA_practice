//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define MOD 1000000007
#define ll long long
class Solution {
  public:
    long long int numberOfPaths(int m, int n){
        // code here
        ll int hold[m][n];
        
        for(int i = 0; i < m; i ++){
            for (int j = 0; j < n; j++){
                hold[i][j] = 1;
            }
        }
    
        for(int i = 1; i < m; i ++){
            for (int j = 1; j < n; j++){
                hold[i][j] = (hold[i - 1][j] + hold[i][j - 1]) % MOD;
            }
        }

        
        return hold[m - 1][n - 1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends