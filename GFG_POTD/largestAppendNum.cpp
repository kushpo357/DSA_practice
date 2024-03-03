//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	
	static bool comp(string a ,string b)
	{
	    string ab = a.append(b);
	    string ba = b.append(a);
	    
	    return (ab.compare(ba) > 0) ? 1 : 0;
	}
	
	string printLargest(int n, vector<string> &arr)
	{
	    // code here
	    
	    sort(arr.begin(),arr.end(),comp);
	    
	    string ans="";
	    
	    for(int i = 0; i < n; i++)
	        ans += arr[i];
	    
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
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
