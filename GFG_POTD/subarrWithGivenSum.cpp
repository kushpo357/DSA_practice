//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        
        int l = 0, r = -1;
        long long currval = 0;
        if(!s) return {-1};
        while(r < n)
        {
            while(currval > s && l <= r)
            {
                currval -= arr[l];
                l++;
                if(currval == s && r < n)
                    return {l + 1, r + 1};
            }
            if(l > r)
            {
                r = l;
                currval = arr[r];
                if(currval == s && r < n) return {l + 1, r + 1};
            }
            while(currval < s)
            {
                if(r == n) break;
                r++;
                currval += arr[r];
                if(currval == s && r < n)
                    return {l + 1, r + 1};
            }
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
