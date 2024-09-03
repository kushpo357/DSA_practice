//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.size(), m = str2.size();
	    
	    //Calculating lcs
	    vector<vector<int>> lcs(n + 1, vector<int> (m + 1, 0));
	    for(int i = n - 1; i >= 0; i--)
	    {
	        for(int j = m - 1; j >= 0; j--)
	        {
	            lcs[i][j] = max(lcs[i + 1][j], lcs[i][j + 1]);
	            
	            if(str1[i] == str2[j])
	            {
	                lcs[i][j] = max(lcs[i][j], 1 + lcs[i + 1][j + 1]);
	            }
	        }
	    }
	    
	    //ans = n - lcs[0][0](char to be deleted) + m - lcs[0][0](char to be inserted)
	    return n + m - 2*lcs[0][0];
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
