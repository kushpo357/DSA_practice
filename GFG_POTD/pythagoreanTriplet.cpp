//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    
	    int maxi = 0;
	    
	    for(int i = 0; i < n; i++) maxi = max(maxi, arr[i]);
	    
	    vector<bool>  exist(maxi + 1, 0);
	    
	    for(int i = 0; i < n; i++)
	    {
	        exist[arr[i]] = 1;
	    }
	    
	    for(int i = maxi + 1; i >= 1; i--)
        {
            if(!exist[i]) continue;
            for(int j = i - 1; j >= 1; j--)
            {
                if(!exist[j]) continue;
                int temp = i*i - j*j;
                int sqrttemp = sqrt(temp);
                if(sqrttemp*sqrttemp == temp)
                {
                    if(exist[sqrttemp]) return 1;
                }
            }
        }
        
        return 0;
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
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends
