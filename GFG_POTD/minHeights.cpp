//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    int getMinDiff(int arr[], int n, int k) {
        // code here
        
        if(n == 1) return 0;
        sort(arr , arr + n);
        
        int ans = arr[n - 1] - arr[0];
        
        vector<int> small(n), big(n);
        
        for(int i = 0; i < n; i++)
        {
            small[i] = arr[i] - k;
            big[i] = arr[i] + k;
            
        }
        
        for(int i = 0; i < n; i++)
        {
            int currmaxval = max(big[i], small[n - 1]);
            int currminval = big[0];
            if(i < n - 1) currminval = min(currminval, small[i + 1]);
            if(currminval <= 0) continue;
            
            ans = min(ans, abs(currmaxval - currminval));
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
