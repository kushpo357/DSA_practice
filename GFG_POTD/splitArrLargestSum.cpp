//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int splitArray(int arr[] ,int n, int k) {
        // code here
        
        int l = INT_MIN, r = 0;
        
        for(int i = 0; i < n; i++)
        {
            l = max(l, arr[i]);
            r += arr[i];
        }
        
        int ans = l;
        
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            int count = 0;
            int currsum = 0;
            for(int i = 0; i < n; i++)
            {
                if(currsum + arr[i] > mid)
                {
                    count++;
                    currsum = arr[i];
                    continue;
                }
                
                currsum += arr[i];
            }
            count++;
            if(count > k) l = mid + 1;
            else if(count <= k)
            {
                ans = mid;
                r = mid - 1;
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
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
