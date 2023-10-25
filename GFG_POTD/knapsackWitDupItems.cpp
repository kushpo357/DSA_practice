//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int val[], int wt[], int n, int w, vector<int> &maxval)
    {
        if(maxval[w] != -1) return maxval[w];
        int i = lower_bound(wt, wt + n - 1, w) - wt;
        if(i == n || wt[i] > w) i--;
        else if(wt[i] == w)
        {
            while(i < n && wt[i + 1] == wt[i]) i++;
        }
        
        int ans = 0;
        for(; i >= 0; i--)
        {
            if(maxval[w - wt[i]] == -1)
                maxval[w - wt[i]] = solve(val, wt, n, w - wt[i], maxval);
            ans = max(ans, val[i] + maxval[w - wt[i]]);
        }
        
        return maxval[w] = ans;
    }
    static bool compare(pair<int, int> &a, pair<int, int> &b)
    {
        if(a.first < b.first) return true;
        else if(a.first == b.first)
        {
            if(a.second < b.second) return true;
            return false;
        }
        
        return false;
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        
        vector<pair<int, int>> v;
        
        for(int i = 0; i < n; i++)
            v.push_back({wt[i], val[i]});
            
        sort(v.begin(), v.end(), compare);
        
        for(int i = 0; i < n; i++)
        {
            val[i] = v[i].second;
            wt[i] = v[i].first;
        }
        
        if(w < wt[0]) return 0;
        vector<int> maxval(w + 1, -1);
        
        for(int i = 0; i < wt[0]; i++)
        {
            maxval[i] = 0;
        }
        return solve(val, wt, n, w, maxval);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
