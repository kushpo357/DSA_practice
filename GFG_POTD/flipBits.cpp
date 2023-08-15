//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        
        int l = 0, r = -1;
        int ans = 0, tempans = 0;
        while(r < n)
        {
            if(r < l)
            {
                r = l;
                tempans = !a[r] ? 1 : -1;
                ans = max(ans, tempans);
            }
            while(tempans > 0)
            {
                r++;
                if(r == n) break;
                if(!a[r]) tempans++;
                else tempans--;
                
                ans = max(ans, tempans);
            }
            while(l <= r)
            {
                if(!a[l]) tempans--;
                else tempans++;
                ans = max(ans, tempans);
                l++;
            }
        }
        
        for(int i = 0; i < n; i++) 
            if(a[i]) ans++;
            
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends
