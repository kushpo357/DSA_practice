//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, vector<int>& wt, vector<int>& val) {
        // Your code here
        
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(w + 2, 0));
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = w; j >= 0; j--)
            {
                dp[i][j] = dp[i + 1][j];
                if(j + wt[i] <= w)
                {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j + wt[i]] + val[i]);
                }
            }
        }
        
        return dp[0][0];
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends
