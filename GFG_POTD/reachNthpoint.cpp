//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	
	#define MOD 1000000007
		int nthPoint(int n){
		    // Code here
		    
		    long long prev = 1, curr = 1;
		    
		    for(int i = n - 2; i >= 0; i--)
		    {
		        curr = (prev % MOD + curr % MOD) % MOD;
		        prev = (curr - prev + MOD )% MOD;
		    }
		    
		    return (int)curr%MOD;
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
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
