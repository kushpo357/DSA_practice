//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        long long left = 1ll << 31ll;
        // cout<<(long long)log2(left)<<endl;
        long long right = 1;
        long long ans = 0;
        while(left)
        {
            if(left & x) ans = ans | right;
            left = left >> 1;
            right = right << 1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends
