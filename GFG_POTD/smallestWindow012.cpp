//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        
        int n = s.size();
        int l = 0, r = -1;
        int ans = 0;
        int freq[3] = {0};
        
        while(r < n)
        {
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
            {
                ans = ans ? min(ans, r - l + 1) : (r - l + 1);
                freq[s[l] - '0']--;
                l++;
            }
            
            if(r  == n - 1) break;
            
            r++;
            freq[s[r] - '0']++;
        }
        
        if(ans == 0) return - 1;
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends
