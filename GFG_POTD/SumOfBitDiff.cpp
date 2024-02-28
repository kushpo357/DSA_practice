//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	    
	    int maxval = 0;
	    
	    for(int i = 0; i < n; i++) maxval = max(maxval, arr[i]);
	    
	    int size = 0;
	    
	    while(maxval)
	    {
	        maxval = maxval >> 1;
	        size++;
	    }
	    
	    vector<int> bitCheck(size, 0);
	    
	    for(int i = 0; i < n; i++)
	    {
	        int temp = arr[i];
	        int bit = 0;
	        while(temp)
	        {
	            if(temp & 1)
	            {
	                bitCheck[bit]++;
	            }
	            
	            temp = temp >> 1;
	            bit++;
	        }
	    }
	    
	    long long ans = 0;
	    
	    for(int i = 0; i < n; i++)
	    {
	        int temp = arr[i];
	        int bit = 0;
	        int tempsize = size;
	        while(tempsize--)
	        {
	            if(temp & 1)
	            {
	                ans += n - bitCheck[bit];
	            }
	            else
	            {
	                ans += bitCheck[bit];
	            }
	            bit++;
	            temp = temp >> 1;
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
