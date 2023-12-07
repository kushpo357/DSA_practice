//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    
    long countSubarrays(int a[], int n, int l, int r) {
       // Complete the function
       
        int s = 0;
        long cu = 0, cl = 0;

        for (int i = 0; i < n; ++i)
        {
            if (a[i] > r) s = i + 1;
            cu += i - s + 1;
        }

        s = 0;

        for (int i = 0; i < n; ++i) 
        {
            if (a[i] > l - 1) s = i + 1;
            cl += i - s + 1;
        }

        return cu - cl;
    }
};



//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends
