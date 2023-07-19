//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string a) {
        //code here
        int n = a.size();
        string reva = a;
        reverse(reva.begin(), reva.end());
        vector<int> curr(n + 1, 0), next(n + 1, 0);
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(a[i] == reva[j]) curr[j] = 1 + next[j + 1];
                else curr[j] = max(next[j], curr[j + 1]);
            }
            next = curr;
        }
        return next[0];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends