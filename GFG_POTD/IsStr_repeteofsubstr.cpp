//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    // Your Code Here
	    if(n%k) return 0;
	    if(n == k || n == 2*k) return 1;
	    
	    map<string, int> mp;
	    
	    for(int i = 0; i < n; )
	    {
	        string curr;
	        for(int j = 0; j < k; j++, i++)
	        {
	            curr.push_back(s[i]);
	        }
	        mp[curr]++;
	        if(mp.size() > 2) return 0;
	    }
	    
	    if(mp.size() == 1) return 1;
	    auto it1 = mp.begin();
	    auto it2 = mp.begin();
	    advance(it2, 1);
	    
	    if((it1->second == 1 && it2->second >= 1) || (it1->second >= 1 && it2->second == 1))
	    return 1;
	    
	    return 0;
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
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends
