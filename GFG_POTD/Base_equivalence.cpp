//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string baseEquiv(int N, int M){
        // code here
        long long n = (long long) N;
        long long m = (long long) M;
        
        for(long long i = 2; i <= 32; i++)
        {
            if(power(i,m - 1) <= n && n < power(i,m))
                return "Yes";
            else if(n < power(i,m - 1))
                return "No";
        }
        return "No";
    }
    long long power(long long i, long long m)
    {
        long long ans = 1;
        while(m--)
            ans = ans*i;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends