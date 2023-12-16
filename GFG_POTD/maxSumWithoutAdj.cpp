//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    
	    if(n == 1) return arr[0];
	    if(n == 2) return max(arr[1], arr[0]);
	    if(n == 3) return max(arr[0] + arr[2], arr[3]);
	    
	    
	    long long a, b, c, d;
	    
	    d = arr[n - 1];
	    c = arr[n - 2];
	    b = arr[n - 3] + arr[n - 1];
	    a = 0;
	    
	    for(int i = n - 4; i >= 0; i--)
	    {
	        a = arr[i] + max(c, d);
	        d = c;
	        c = b;
	        b = a;
	    }
	    
	    return max(b, c);
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
