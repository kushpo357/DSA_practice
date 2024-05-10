//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> jugglerSequence(int n) {
        // code here
        
        vector<int> ans;
        ans.push_back(n);
        while(n != 1)
        {
            if(n & 1)
            {
                ans.push_back((int)sqrt(pow(n, 3)));
            }
            else
            {
                ans.push_back((int)sqrt(n));
            }
            n = ans.back();
        }
        
        return ans;
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
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
