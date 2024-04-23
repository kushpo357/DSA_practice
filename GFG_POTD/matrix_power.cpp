//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define MOD 1000000007
class Solution {
  public:
    int firstElement(int n) {
        // code here
        if(n == 1 || n == 2) return 1;
        
        int a = 1, b = 1, c = 0; 
        for(int i = 1; i <= n - 2; i++)
        {
            c = (a%MOD + b%MOD)%MOD;
            b = a%MOD;
            a = c%MOD;
        }
        
        return c;
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
