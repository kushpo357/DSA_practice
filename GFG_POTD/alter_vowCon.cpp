//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string s, int n)
    {
        // your code here
        if(n == 1)
            return s;
        int vlen = 0, clen = 0;
        
        map<char, int> v, c;
        for(int i = 0; i < n; i++)
        {
            if(s[i]=='a'||s[i]=='i'||s[i]=='e'||s[i]=='o'||s[i]=='u')
            {
                vlen++;
                v[s[i]]++;
            }
            else
            {
                clen++;
                c[s[i]]++;
            }
        }
        
        if(abs(clen - vlen) > 1)
            return "-1";
         
        map<char, int> :: iterator itv = v.begin(), itc = c.begin();
        
        if(vlen >= clen)
        {
            if(vlen == clen && *c.begin() < *v.begin())
            {
                for(int i = 0; i < n; i++)
                {
                    s[i] = itc->first;
                    if(itc->second - 1)
                        itc->second--;
                    else
                        itc++;
                    
                    i++;
                    
                    s[i] = itv->first;
                    if(itv->second - 1)
                        itv->second--;
                    else
                        itv++;
                }
            }
            else
            {
                for(int i = 0; i < n; i++)
                {
                    s[i] = itv->first;
                    if(itv->second - 1)
                        itv->second--;
                    else
                        itv++;
                    
                    i++;
                    
                    s[i] = itc->first;
                    if(itc->second - 1)
                        itc->second--;
                    else
                        itc++;
                }
            }
        }
        else
        {   
            for(int i = 0; i < n; i++)
            {
                s[i] = itc->first;
                if(itc->second - 1)
                    itc->second--;
                else
                    itc++;
                
                i++;
                
                s[i] = itv->first;
                if(itv->second - 1)
                    itv->second--;
                else
                    itv++;
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
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends