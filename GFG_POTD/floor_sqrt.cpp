//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        
        if(n == 1)
            return 1;
            
        long long l = 2, r = n;
        long long mid = 0;
        while(l <= r)
        {
            mid = l + (r - l)/2;
            
            if(mid*mid == n)
            {
                return mid;
            }
            else if(mid*mid < n)
                l = mid + 1;
            else 
                r = mid - 1;
        }
        
        if(mid*mid > n)
            mid--;
        
        return mid;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
