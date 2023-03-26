//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int countWaystoDivide(int n, int k) {
        // Code here
        
        vector<vector<int>> ways(n + 1, vector<int> (k + 1, 0));
        
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= k; j++)
            {
                if(i == j)
                    ways[i][j] = 1;
                else if(i > j)
                    ways[i][j] = ways[i - 1][j - 1] + ways[i - j][j];
            }
        }
        
        return ways[n][k];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends