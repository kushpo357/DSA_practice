//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string s, string t) {
        // code here
        int slen = s.size(), tlen = t.size();
        
        int i = 0, j = 0;
        while( i < slen && j < tlen)
        {
            if(isalpha(t[j]) && t[j] != s[i])
                    return 0;
            else if(!isalpha(t[j]))
            {
                int num = 0;
                while(!isalpha(t[j]) && j < tlen)
                    num = num*10 + t[j++] - 48;
                i += num - 1;
                j--;
            }
            
            i++;
            j++;
            
        }
        if(slen - i != tlen - j) return 0;
        return 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends