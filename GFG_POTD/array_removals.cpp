//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        //Code here
        sort(arr.begin(), arr.end());
        int count = INT_MAX, n = arr.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = n - 1; j >= i; j--)
            {
                if(arr[j] - arr[i] <= k)
                {
                    //cout<<i<<' '<<j<<endl;
                    count = min(count,n - j + i - 1);
                    //cout<<count<<endl;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends