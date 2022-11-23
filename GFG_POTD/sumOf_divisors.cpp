//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long int maxSumLCM(int n) 
    {
        // code here
        long long ans = 0;
        int i = 1;
        
        while(i*i <= n)
        {
            if(!(n % i))
            {
                ans += i;
                ans += n/i;
            }
            i++;
        }
        i--;
        
        if(i*i == n)
            ans -= i;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.maxSumLCM(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends