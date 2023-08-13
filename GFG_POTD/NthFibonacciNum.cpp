//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    #define MOD 1000000007
    int nthFibonacci(int n){
        // code here
        
        vector<int> v(n + 1, 0);
        
        v[1] = 1;
        
        for(int i = 2; i <= n; i++)
            v[i] = (v[i - 1]%MOD + v[i - 2]%MOD)%MOD;
        
        return v[n];
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends