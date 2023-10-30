//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    	
    	vector<long long int> setbits(17, 0);
    	
    	for(int i = 0; i < n; i++)
    	{
    	    for(int j = 0; j < 17; j++)
    	    {
    	        if((1<<j) & arr[i])
    	            setbits[j]++;
    	    }
    	}
    	
    	long long int ans = 0;
    	
    	for(long long int i = 0; i < 17; i++)
    	{
    	    ans += ((((long long int)n - setbits[i])<<i)*setbits[i]);
    	}
    	
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
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends
