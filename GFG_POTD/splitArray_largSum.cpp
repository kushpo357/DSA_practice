//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int n, int k) {
        // code here
        
        int low = INT_MIN, high = 0;
        
        for(int i = 0; i < n; i++)
        {
            low = max(low, arr[i]);
            high += arr[i];
        }
        
        
        int ans, mid;
        while(low <= high)
        {
            
            mid = (low + high)/2;
            int subarr = 1, su = 0;
            
            for(int i = 0; i < n; i++){
                
                su += arr[i];
                if(su > mid)
                {
                    subarr++;
                    su = arr[i];
                }
            }
            
            if(subarr > k)
                low = mid + 1;
            else
            {
                ans = mid;
                high = mid - 1;
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