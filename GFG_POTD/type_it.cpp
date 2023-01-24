//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        
        int repeat=0;
        
        int n = s.length();
        
        for(int i=0;i<s.length();i++)
        {
            if(s[0]==s[i])
            {   
                int p=i;
                int j;
                
                for( j=1;j<i;j++)
                {
                    if(p<n-1 && s[j]==s[p+1] )
                      p++;
                    else
                       break;
                }
                
                if(j==i)
                    repeat=max(repeat,i);

            }
        }
        
        if(repeat!=0)
            return repeat +1+(s.length()-2*repeat);
        else
            return s.length();
        
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
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends