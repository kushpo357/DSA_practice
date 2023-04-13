//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    pair<long long, long long> minmax(long long pre[], int l, int r)
    {
        int low = l, high = r - 1;
        long long minsum = 0, maxsum = pre[r] - pre[l - 1];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long lsum = pre[mid] - pre[l - 1], rsum = pre[r] - pre[mid];
            if(abs(rsum - lsum) < maxsum - minsum)
            {
                minsum = min(lsum, rsum);
                maxsum = max(lsum, rsum);
            }
            if(lsum < rsum) low = mid + 1;
            else high = mid - 1;
        }
        return {minsum, maxsum};
    }
    long long minDifference(int n, vector<int> &a) {
        // code here
        long long presum[n + 1];
        presum[0] = 0;
        
        for(int i = 1; i <= n; i++) presum[i] = presum[i - 1] + a[i - 1];
        
        long long ans = presum[n];
        for(int i = 1; i < n - 2; i++)
        {
            pair<long long, long long> mml = minmax(presum, 1, i + 1), mmr = minmax(presum, i + 2, n);
            ans = min(ans, max(mml.second, mmr.second) - min(mml.first, mmr.first));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        long long ans = ob.minDifference(N, A);
        cout<<ans<<endl;
    }
    return 0;
} 
// } Driver Code Ends