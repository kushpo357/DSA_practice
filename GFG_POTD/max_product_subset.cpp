//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    long long int findMaxProduct(vector<int>& arr) {
        //Code here
        
        int n = arr.size();
        
        if(n == 1) return arr[0];
        int k = 0,r = 0;
        
        long long mod = 1000000007;
        
        int maxi = INT_MIN;
        long long int ans = 1;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] != 0)
            {
                ans = (ans * arr[i]) % mod;
                r = 1;
            }
            else
            {
                k = 1;
            }
            if(arr[i] < 0 && arr[i] > maxi)
            maxi = arr[i];
        }
        
        if(r != 1) return 0;
        
        if(arr.size() == 2 && k == 1 && ans < 0)
        return 0;
        
        if(ans<0) ans/=maxi;
        
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
