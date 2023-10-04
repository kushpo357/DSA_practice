//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        
        int ans = 0;
        int ind = 0;
        int n = str.size();
        while(ind <= n && str[ind] == 'M')
        {
            ans += 1000;
            ind++;
        }
        if(ind <= n && str[ind] == 'C' && str[ind + 1] == 'M')
        {
            ans += 900;
            ind += 2;
        }
        if(ind <= n && str[ind] == 'D')
        {
            ans += 500;
            ind++;
        }
        if(ind <= n && str[ind] == 'C' && str[ind + 1] == 'D')
        {
            ans += 400;
            ind += 2;
        }
        while(ind <= n && str[ind] == 'C')
        {
            ans += 100;
            ind++;
        }
        if(ind <= n && str[ind] == 'X' && str[ind + 1] == 'C')
        {
            ans += 90;
            ind += 2;
        }
        if(ind <= n && str[ind] == 'L')
        {
            ans += 50;
            ind++;
        }
        if(ind <= n && str[ind] == 'X' && str[ind + 1] == 'L')
        {
            ans += 40;
            ind += 2;
        }
        while(ind <= n && str[ind] == 'X')
        {
            ans += 10;
            ind++;
        }
        if(ind <= n && str[ind] == 'I' && str[ind + 1] == 'X')
        {
            ans += 9;
            ind += 2;
        }
        if(ind <= n && str[ind] == 'V')
        {
            ans += 5;
            ind++;
        }
        if(ind <= n && str[ind] == 'I' && str[ind + 1] == 'V')
        {
            ans += 4;
            ind += 2;
        }
        while(ind <= n && str[ind] == 'I')
        {
            ans += 1;
            ind++;
        }
        
        return ans;
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
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends
