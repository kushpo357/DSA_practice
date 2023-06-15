//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    string longestPalin (string s) 
    {
        // code here
        
        int l = 0, r = 0, n = s.size();
        int low = 0, high = 0;
        for(int i = 0; i < n; i++)
        {
            low = i - 1;
            high = i;
            while(low >= 0 && high < n && s[low] == s[high])
            {
            
                if(high - low + 1 > r)
                {
                    r = high - low + 1;
                    l = low;
                }
                low--;
                high++;
            }
            low = i - 1;
            high = i + 1;
            while(low >= 0 && high < n && s[low] == s[high]){
                
                if(high - low + 1 > r)
                {
                    r = high - low + 1;
                    l = low;
                }
                low--;
                high++;
            }
        
        }
        if(r == 0) return s.substr(l,1);
    
        return s.substr(l,r);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends