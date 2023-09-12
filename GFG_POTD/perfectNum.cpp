//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long n) {
        // code here
        long long num = 1;
        for(long long i = 2; i*i <= n; i++)
        {
            if(!(n%i))
            {
                num += i;
                if(i*i != n)
                    num += n/i;
            }
        }
        if(n == 1) return 0;
        return num == n;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
