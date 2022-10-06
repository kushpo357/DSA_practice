//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string lexicographicallySmallest(string S, int k) {
        // code here
        stack<char> sta;
        int ind;
        int len = S.size();
        string ans = "";
    
        (len & (len - 1)) ? k *= 2 : k /= 2;
        
        if(k >= len)
            return "-1";
            
        for(int i = 0; i < len; i++)
        {
            while(!ans.empty() && k > 0 && ans.back() > S[i])
            {
                ans.pop_back();
                k--;
            }
            ans.push_back(S[i]);
        }
        
        while(k--)
            ans.pop_back();
            
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int k;
        cin >> S >> k;
        Solution ob;
        cout << ob.lexicographicallySmallest(S, k) << endl;
    }
    return 0;
}

// } Driver Code Ends