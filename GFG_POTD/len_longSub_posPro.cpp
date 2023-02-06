//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
        //code here
        int ans = 0;
        int i = 0, j = 0;
        int p = 1;
        int min1 = n;
        while(j < n)
        {
            p *= arr[j];
            
            if(p < 0)
            {
                min1 = min(min1, j);
                ans = max(ans, j - min1);
                p = -1;
            }
            
            if(p>0)
            {
               ans = max(ans, j - i + 1);
               p = 1;
            }
            
            else if( p == 0 )
            {
                min1 = n;
                p=1;
                i=j+1;
            }
            
            j++;
        }
        
        return ans;
            
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends