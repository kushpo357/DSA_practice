//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

    #define MOD 1000000007

    int TotalWays(int n) {
        // Code here

        if (n == 1) return 4;
        if (n == 2) return 9;

        long long a = 3, b = 2;
        
        for (int i = n - 3; i >= 0; i--) {
            long long c = ((a % MOD) + (b % MOD)) % MOD;
            b = a;
            a = c;
        }

        return ((a % MOD) * (a % MOD)) % MOD;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
