//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int n, int k) {
        // code here
        int ans = 0;
        vector<int> fac(k, 0);
        
        //for(int i = 0; i < k; i++)
        //    fac[i] = 0;
        
        //cout<<0<<' '<<fac[0]<<endl;
        for(int i = 0; i < n; i++)
        {
            fac[(arr[i]%k)]+=1;
            //cout<<(arr[i]%k)<<' '<<fac[(arr[i]%k)]<<endl;
        }
        
        if(fac[0])
            ans++;
            
        if(!(k & 1) && fac[k/2])
            ans++;
            
        for(int i = 1; i < k/2 + (k & 1); i++)
        {
            //cout<<i<<' '<<fac[i]<<' '<<fac[k - i]<<endl;
            ans += max(fac[i], fac[k - i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends