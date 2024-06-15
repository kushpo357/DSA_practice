//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        
        vector<vector<long long>> neighbours = {{8}, {2, 4}, {1, 3, 5}, {2, 6}, {1, 5, 7}, {2, 4, 6, 8}, {3, 5, 9}, {4, 8}, {5, 7, 9, 0}, {6, 8}};
        
        vector<long long> prev(10, 1);
        vector<long long> next(10, 1);
        for(long long i = 1; i < n; i++)
        {
            for(long long j = 0; j < 10; j++)
            {
                for(long long k = 0; k < neighbours[j].size(); k++)
                {
                    next[j] += prev[neighbours[j][k]];
                }
            }
            
            prev = next;
        }
        
        long long ans = 0;
        
        for(long long i = 0; i < 10; i++)
        {
            ans += prev[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends
