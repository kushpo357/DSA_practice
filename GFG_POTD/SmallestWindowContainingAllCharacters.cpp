//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        
        int n = s.size();
        int len = p.size();
        vector<int> freq(26, 0);
        for(int i = 0; i < len; i++)
        {
            freq[p[i] - 'a']++;
        }
        
        int count = 0;
        vector<int> currfreq(26, 0);
        pair<int, int> minWindow = {0, n + 1};
        int i = 0, j = 0;
        while(j < n)
        {
            if(count < len)
            {
                currfreq[s[j] - 'a']++;
                if(freq[s[j] - 'a'] >= currfreq[s[j] - 'a'])
                {
                    count++;
                }
                j++;
            }
            else
            {
                currfreq[s[i] - 'a']--;
                if(currfreq[s[i] - 'a'] < freq[s[i] - 'a'])
                {    
                    count--;
                }
                i++;
            }
            if(count == len)
            {
                if((minWindow.second - minWindow.first) > (j - i))
                {
                    minWindow = {i, j};
                }
            }
        }
        
        while(count == len)
        {
            if((minWindow.second - minWindow.first) > (j - i))
            {
                minWindow = {i, j};
            }
            currfreq[s[i] - 'a']--;
            if(currfreq[s[i] - 'a'] < freq[s[i] - 'a'])
            {    
                count--;
            }
            i++;
        }
        
        if(minWindow.second - minWindow.first == (n + 1))
            return "-1";
            
            
        return s.substr(minWindow.first, minWindow.second - minWindow.first);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
