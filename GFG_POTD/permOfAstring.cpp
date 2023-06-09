//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void solve(vector<string> & ans, string s, string curr, int rem, int len)
	{
	    curr.push_back(s[rem]);
	    s.erase(s.begin() + rem);
	    len--;
	    if(!len)
	    {
	        ans.push_back(curr);
	        return;
	    }
	    for(int i = 0; i < len; i++) 
	    {
	        if(i && s[i] == s[i - 1]) continue;
	        solve(ans, s, curr, i, len);
	    }
	}
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    sort(s.begin(), s.end());
		    int len = s.size();
		    vector<string> ans;
		    
		    for(int i = 0; i < len; i++) solve(ans, s, "", i, len);
		    sort(ans.begin(), ans.end());
		    
		    int n = ans.size();
		    for(int i = 1; i < n; i++)
		    {
		        if(ans[i] == ans[i - 1])
		        {
		            ans.erase(ans.begin() + i);
		            n--;
		            i--;
		            continue;
		        }
		    }
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends