//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
 
    vector<vector<long long>> v;
    vector<vector<long long>> dp;
    
    long long help(int i,bool flag)
    {
        if(i == v.size()) return abs(v[i - 1][flag]);
        
        if(dp[i][flag] != -1) return dp[i][flag];
        
        long long ans = help(i + 1, !flag) + abs(v[i - 1][flag] - v[i][flag]);
        
        ans = min(ans, help(i + 1, flag) + abs(v[i - 1][flag] - v[i][!flag]));
        
        return dp[i][flag] = ans + (long long)abs(v[i][0] - v[i][1]);
    }
    
    long long minTime(int n, vector<int> &l, vector<int> &t) {
        // code here
        
        map<int,vector<long long>> mp;
        
        for(int i = 0; i < l.size(); i++)
        {
            if(!mp.count(t[i])) mp[t[i]] = {l[i],l[i]};
            else
            {
                mp[t[i]][0] = min(mp[t[i]][0], (long long)l[i]);
                mp[t[i]][1] = max(mp[t[i]][1], (long long)l[i]);
            }
        }
        
        v.resize(0);
        v.push_back({0,0});
        
        for(auto it : mp) v.push_back(it.second);
        
        dp.resize(v.size(),vector<long long>(2,-1));
        return help(1,0);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends