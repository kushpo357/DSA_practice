//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<int> v = arr;
        vector<long long> sum(n, 0);
        long long total = 0;
        sort(v.begin(), v.end());
        sum[0] = 0;
        for(int i = 1; i < n; i++)
        {
            total += v[i - 1];
            if(v[i] > v[i - 1]) sum[i] = total;
            else sum[i] = sum[i - 1];
        }
        
        vector<long long> ans(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            int l = 0, h = n - 1;
            int mid;
            while(l <= h)
            {
                mid = l + (h - l)/2;
                if(arr[i] == v[mid]) 
                {
                    ans[i] = sum[mid];
                    break;
                }
                if(arr[i] < v[mid])
                {
                    h = mid - 1;
                }
                else l = mid + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends