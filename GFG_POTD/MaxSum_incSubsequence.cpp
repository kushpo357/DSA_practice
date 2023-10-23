//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    
	    vector<int> sum(n, 0);
	    sum[n - 1] = arr[n - 1];
	    int ans;
	    ans = arr[n - 1];
	    for(int i = n - 2; i >= 0; i--)
	    {
	        sum[i] = arr[i];
	        int temp = 0;
	        for(int j = i + 1; j < n; j++)
	        {
	            if(arr[j] > arr[i])
	            temp = max(temp, sum[j]);
	        }
	        
	        sum[i] += temp;
	        
	        ans = max(ans, sum[i]);
	    }
	    
	    return ans;
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
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
