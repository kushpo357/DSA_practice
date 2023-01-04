//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        map<string, int> mp;
        for(auto it: words)
            mp[it] = 1;
            
        string ans = "";
        int count = 0;
        for(auto it : mp)
        {
            string s = it.first;
            string k = "";
            bool flag = true;
            
            for(int i = 0; i < s.length(); i++)
            {
                k += s[i];
                if(!mp[k])
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag && count < s.length())
            {
                ans = s;
                count = s.length();
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends