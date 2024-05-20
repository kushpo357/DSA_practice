//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    long long power(long long x, long long n, long long M)
	    {}
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    
		    if(n == 0) return 1;
		    long long ans = 1;
		    
		    
		    long long halfval = PowMod(x, n/2, M)%M;
		    ans = ((halfval%M)*(halfval%M)%M);
		    if(n & 1) ans = ans*x%M;
		    
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends
