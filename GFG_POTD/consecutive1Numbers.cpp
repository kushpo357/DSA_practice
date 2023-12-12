//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    //#define ll long long
    #define MOD 1000000007
	ll countStrings(int n) {
	    // code here
	    
	    if(n == 1) return 2;
	    if(n == 2) return 3;
	    
	    ll ans = 1;
	    ll lastele = 1;
	    ll thisele = 0;
	    
	    for(int i = n - 3; i >= 0; i--)
	    {
	        thisele = (1 + ans % MOD) % MOD;
	        ans = ((ans % MOD) + lastele % MOD) % MOD;
	        lastele = thisele;
	    }
	    
	    return (ans % MOD + 1 + thisele % MOD) % MOD;
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
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
