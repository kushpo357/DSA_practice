//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    long long nCr(long long n, long long r){
        
        if(n == 0 || n < r) return 0;
        
        long long num = 1;
        
        if (r > n - r)
            r = n - r;
            
        for (int i = 0; i < r; ++i) {
            
            num *= (n - i);
            num /= (i + 1);
        }
        
        return num;
    }
        
    long long count(long long x) {
        
        long long ans = 0;
        
        int o = 0, z = 0;
        
        for(int i = 0; i < 64;++i){

            if(x & 1){
                
                o++;
                long long nCr_r = nCr(i , o);
                ans += nCr_r;
            }
            
            x = x >> 1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends