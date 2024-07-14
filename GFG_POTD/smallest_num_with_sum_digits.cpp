//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        
        if(!s || 9*d < s)
            return "-1";
        
        if(10 <= s)
        {
            string ans = smallestNumber(s - 9, d - 1);
            ans.push_back('9');
            return ans;
        }
        string ans = "";
        if(d == 1)
        {
            ans.push_back('0' + s);
            return ans;
        }
        ans.push_back('1');
        s--;
        for(int i = 0; i < d - 2; i++)
        {
            ans.push_back('0');
        }
        ans.push_back('0' + s);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends
