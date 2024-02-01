//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int n = s.size();
        bool isneg = false;
        int i = 0;
        if(s[0] == '-')
        {
            i++;
            isneg = true;
            if(n == 1) return -1;
        }
        int ans = 0;
        for(; i < n; i++)
        {
            if(!isdigit(s[i])) return -1;
            ans *= 10;
            ans += s[i] - '0';
        }
        
        if(isneg) ans *= -1;
        
        return ans;
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
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends
