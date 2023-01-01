//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	const int mod = 1e9 + 7;
	int modinv(int n, int m)
	{
	    if(m == 0) return 1;
	    if(m & 1) return (n*1ll*modinv(n, m - 1))%mod;
	    int temp = modinv(n, m/2);
	    return (temp*1ll*temp)%mod;
	}
	int compute_value(int n)
	{
	    // Code here
	    long long f2n = 1, fn;
	    for(int i = 1; i <= 2*n; i++)
	    {
	        f2n *= i;
	        f2n %= mod;
	        if(i == n) fn = f2n;
	    }
	    fn = (fn*fn)%mod;
	    return (f2n*1ll*modinv(fn, mod - 2))%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends