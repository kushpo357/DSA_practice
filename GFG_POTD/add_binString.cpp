//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	    // your code here
	    int lena = a.size(), lenb = b.size(), carry = 0;
	    string ans;
	    
	    int ai = lena - 1, bi = lenb - 1;
	    while(ai >= 0 && bi >= 0)
	    {
	        carry += a[ai] + b[bi] - 96 ;
	        ans.push_back(48 + carry%2);
	        carry /= 2;
	         ai--;
	         bi--;
	    }
	    
	    if(lena > lenb)
	    {
	        while(ai >= 0)
	        {
	            carry += a[ai] - 48;
	            ans.push_back(48 + carry%2);
	            carry /= 2;
	            ai--;
	        }
	        if(carry)
	            ans.push_back(49);
	    }
	    else
	    {
	        while(bi >= 0)
	        {
	            carry += b[bi] - 48;
	            ans.push_back(48 + carry%2);
	            carry /= 2;
	            bi--;
	        }
	        if(carry)
	            ans.push_back(49);
	    }
	    
	    while(!(ans.back() - 48))
	    {
	        ans.pop_back();
	    }
	    
	    reverse(ans.begin(), ans.end());
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends