//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            reverse(s.begin(), s.end());
            int n = s.size();
            
            for(int i = 0; i < n; i++)
            {
                if((s[i] >= '0' && s[i] <= '9'))
                {
                    int j = i;
                    while(i < n && (s[i] >= '0' && s[i] <= '9')) i++;
                    reverse(s.begin() + j, s.begin() + i);
                }
            }
            
            return s;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends