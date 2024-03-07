//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  
    string longestSubstring(string s, int n)
    {
        int maxlen = 0;
        string ans = "-1";
        int i = 0, j = 0;
    
        while (i < n && j < n) 
        {
            string substring = s.substr(i, j - i + 1);
    
            if (s.find(substring, j + 1) != string::npos)
            {
                int len = substring.length();
                if (len > maxlen)
                {
                    maxlen = len;
                    ans = substring;
                }
            } 
            else i++;
            j++;
        }
        return ans;
    }
};

//{ Driver Code starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends
