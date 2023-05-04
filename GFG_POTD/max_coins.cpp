//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    static bool cmp(vector<int> v1, vector<int> v2)
    {   
        if(v1[1] != v2[1]) return v1[1] < v2[1];
        else return v1[0] < v2[0];
    }
    int binsearch(vector<pair<int, int>> &rl, int i)
    {
        int lo = 0, hi = rl.size() - 1, ind = -1;
        
        while(lo <= hi)
        {
            int mid = lo + (hi - lo)/2;
            if(rl[mid].first <= i)
            {
                ind = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        
        return ind == -1 ? 0 : rl[ind].second;
    }
    int maxCoins(int n,vector<vector<int>> &ranges){
        // Code here
        sort(ranges.begin(), ranges.end(), cmp);
        vector<pair<int, int>> rangelist;
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, binsearch(rangelist, ranges[i][0]) + ranges[i][2]);
            
            if(rangelist.empty() || rangelist.back().second < ranges[i][2])
                rangelist.emplace_back(ranges[i][1], ranges[i][2]);
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
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends