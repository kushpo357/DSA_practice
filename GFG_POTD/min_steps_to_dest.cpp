//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minSteps(int d) {
        // code here
        
        int num = 1;
        while(((num*(num + 1))>>1) < d)
            num++;
        
        int sum = (num*(num + 1)) >> 1;
        
        if(sum == d)
            return num;
            
        while((sum & 1) ^ (d & 1))
        {
            num++;
            sum = (num*(num + 1)) >> 1;
        }
            
        return num;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends
