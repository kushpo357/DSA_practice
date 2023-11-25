//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	
	public:
	void shuffleArray(int arr[],int n)
	{
	    // Your code goes here
	    
	    for(int i = 0; i < n; i++) arr[i] *= 1001;
	    
	    for(int i = 0; i < n; i++)
	    {
	        if(i & 1) arr[i] += arr[i/2 + n/2]/1001;
	        else arr[i] += arr[i/2]/1001;
	    }
	    
	    for(int i = 0; i < n; i++) arr[i] %= 1001;
	    
	}
		 

};

//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
