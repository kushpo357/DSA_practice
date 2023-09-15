//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(const int &n, int arr[], int i, long long subsum,const long long &sum, vector<vector<int>> &v)
    {
        if(2*subsum == sum) v[i][subsum] = 1;
        
        if(2*subsum > sum) v[i][subsum] = 0;
        
        if(i == n) v[i][subsum] = 0;
        
        if(v[i][subsum] != - 1)
            return v[i][subsum];
        
        if(v[i + 1][subsum + arr[i]] == -1)
            solve(n, arr, i + 1, subsum + (long long)arr[i], sum, v);
        
        if(v[i + 1][subsum] == -1)
            solve(n, arr, i + 1, subsum, sum, v);
        
        v[i][subsum] = v[i + 1][subsum] + v[i + 1][subsum + arr[i]];
        
        return v[i][subsum];
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        
        long long sum = 0, subsum = 0;
        
        for(int i = 0; i < n; i++) sum += arr[i];
        
        if(sum & 1) return 0;
        
        vector<vector<int>> v(n + 1, vector<int> (sum + 1, -1));
        
        return solve(n, arr, 0, subsum, sum, v);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
