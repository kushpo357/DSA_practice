//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    string isSumOfTwo(int n){
        // code here
        if(n == 1 || n == 2 || n == 3)
            return "No";
        
        if(!(n & 1))
            return "Yes";
            
        bool isPrime = true;
        
        n -= 2;
        
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(n%i == 0)
            {
                isPrime = false;
                break;
            }
        }
        
        if(isPrime)
            return "Yes";
        else
            return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends