//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function
    
    long long int count(long long int n)
    {
    	// Your code here
    	vector<long long int> dp3(n + 1, 0);
    	vector<long long int> dp5(n + 1, 0);
    	vector<long long int> dp10(n + 1, 0);
    	
    	dp10[n] = 1;
    	dp3[n] = 1;
    	dp5[n] = 1;
    	
    	for(int i = n; i >= 0; i--)
    	{
    	    if(i + 10 <= n) dp10[i] += dp10[i + 10];
    	    if(i + 5 <= n) 
    	    {
    	        dp5[i] += dp5[i + 5];
    	        
    	        if(i + 10 <= n) dp5[i] += dp10[i + 10];
    	    }
    	    if(i + 3 <= n) 
    	    {
    	        dp3[i] += dp3[i + 3];
    	        
    	        if(i + 5 <= n) dp3[i] += dp5[i + 5];
    	        
    	        if(i + 10 <= n) dp3[i] += dp10[i + 10];
    	    }
    	}
        return dp3[0];
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
