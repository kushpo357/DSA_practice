//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	bool sameFreq(string s)
	{
	    // code here 
	    
	    int n = s.size();
	    
	    vector<int> freq(26, 0);
	    
	    int unique = 0;
	    
	    for(int i = 0; i < n; i++)
	    {
	        freq[s[i] - 'a']++;
	        
	        if(freq[s[i] - 'a'] == 1) unique++;
	    }
	    
	    int minfreq = INT_MAX, maxfreq = 0;
	    
	    for(int i = 0; i < 26; i++)
	    {
	        maxfreq =  max(maxfreq, freq[i]);
	        if(freq[i])
	        minfreq =  min(minfreq, freq[i]);
	    }
	    
	    if(maxfreq == minfreq) return 1;
	    if(maxfreq - minfreq > 1) return 0;
	    
	    int maxnum = 0, minnum = 0;
	    
	    for(int i = 0; i < 26; i++)
	    {
	        if(freq[i] == maxfreq) maxnum++;
	        if(freq[i] == minfreq) minnum++;
	    }
	    
	    //cout<<maxnum<<' '<<minnum<<' '<<unique<<endl;
	    if(maxnum + minnum != unique) return 0;
	    
	    //cout<<maxnum<<' '<<minnum<<endl;
	    if(maxnum > 1)
	    {
	        if(minnum == 1 && minfreq == 1) return 1;
	        
	        return 0;
	    }
	    
	    return 1;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends
