//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
  
    bool dfs(vector<vector<int>> &adjlist, int n, int ind, vector<int> &vis, vector<int> &ans)
    {
        if(ind >= n) return 1;
        if(vis[ind] == 1) return 1;
        if(vis[ind] == 2) return 0;
        
        vis[ind] = 2;
        for(int i = 0; i < adjlist[ind].size(); i++)
        {
            if(dfs(adjlist, n, adjlist[ind][i], vis, ans) == 0) return 0;
        }
        
        ans.push_back(ind);
        vis[ind] = 1;
        return 1;
    }
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        //code here
        
        vector<vector<int>> adjlist(n);
        
        for(int i = 0; i < m; i++)
        {
            adjlist[pre[i][0]].push_back(pre[i][1]);
        }
        
        vector<int> vis(n, 0);
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++)
        {
            if(dfs(adjlist, n, i, vis, ans) == 0) return {};
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
