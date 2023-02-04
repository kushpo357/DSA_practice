//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) 
	{
	    // code here
	    int n0=0, n1=0, n2=0;
        
        for(int i = n-1; i >= 0; i--)
        {
            int newn1=n1+arr[i]; 
            int newn2=n2+arr[i];
            n2=n1;
            n1=n0;
            n0=max(newn1,newn2);
        }
        
        return max(n0,n1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends