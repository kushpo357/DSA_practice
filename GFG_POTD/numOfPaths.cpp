//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    
    //#define MOD 1000000007
    long long power(long long x, int y, long long p)
    {
        long long res = 1;
        
        while(y > 0)
        {
            if(y & 1) res = (res*x) % p;
            
            y = y / 2;
            x = (x * x)%p;
        }
        
        return res;
    }
    long long  numberOfPaths(int m, int n)
    {
        // Code Here
        
        long long total = m + n - 2;
        long long MOD = 1000000007;
        long long ans = 1;
        
        for(int i = 0; i < m - 1; i++)
        {
            ans = (ans*(n + i))%MOD;
            
            long long temp = power(i + 1, MOD - 2, MOD);
            ans = (ans*temp) % MOD;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends
