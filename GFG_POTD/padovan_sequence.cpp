//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    
    #define MOD 1000000007
    int padovanSequence(int n)
    {
       //code here
       
       if(n == 0 || n == 1 || n == 2)
       return 1;
       
       int a = 1, b = 1, c = 1, d = 1;
       
       for(int i = 3; i <= n; i++)
       {
           d = c;
           c = b;
           b = a;
           a = (c + d)%MOD;
       }
       
       return a;
    }
    
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
