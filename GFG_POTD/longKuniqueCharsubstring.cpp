//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int n = s.size();
    int l = 0, r = 0;
    map<char, int> mp;
    int maxlen = -1;
    while (r < n)
    {
        mp[s[r]]++; 
        while (mp.size() > k) 
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                mp.erase(s[l]);
            l++;
        }

        if (mp.size() == k)
            maxlen = max(maxlen, r - l + 1);

        r++;
    }

    return maxlen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
