//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string s, string t, int m, int n) {
        // code here
        int anums = 0, bnums = 0, anumt = 0, bnumt = 0;
        
        if(m != n)
            return 0;
        
        for(int i = 0; i < n; i++)
        {
           if(s[i] == 'A')
                anums++;
           if(t[i] == 'A')
           {
               if(bnums != bnumt)
                    return 0;
                anumt++;
           }
           if(s[i] == 'B')
           {
                if(anums != anumt)
                    return 0;
                bnums++;
           }
          
           if(t[i] == 'B')
                bnumt++;
                
           if(anums > anumt)
                return 0;
                
           if(bnums < bnumt)
                return 0;
        }
        
    if(anums != anumt || bnums != bnumt)
        return 0;
        
    return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends