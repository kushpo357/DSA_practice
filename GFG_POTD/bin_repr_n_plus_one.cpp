//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        
        int n = s.size();
        bool done = false;
        reverse(s.begin(), s.end());
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                s[i] = '0';
            }
            else
            {
                s[i] = '1';
                done = true;
                break;
            }
        }
        
        if(done && s[n - 1] == '0')
        {
            while(s.back() == '0')
                s.pop_back();
        }
        
        if(!done && s[n - 1])
            s.push_back('1');
            
        reverse(s.begin(), s.end());
            
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
