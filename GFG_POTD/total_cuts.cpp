//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n,int k,vector<int> &a){
        // Code here
        vector<int> maxv(n, INT_MIN), minv(n, INT_MAX);
        maxv[0] = a[0];
        minv[n - 1] = a[n - 1];
        for(int i = 1, j = n - 2; i < n && j >= 0; i++, j--)
        {
            maxv[i] = max(a[i], maxv[i - 1]);
            minv[j] = min(a[j], minv[j + 1]);
        }
        int ans = 0;
        for(int i = 1; i < n; i++)
            if(maxv[i - 1] + minv[i] >= k) ans++;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends