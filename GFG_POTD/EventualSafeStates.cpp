//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int dfs(vector<int> adj[], int i, vector<int>& vis) 
    {
        if (vis[i] == 1) return 1;
        if (vis[i] == 0) return 0;
    
        vis[i] = 0;
        
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (!dfs(adj, adj[i][j], vis)) return 0;
        }
        
        return vis[i] = 1;
    }
    
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
        
        vector<int> vis(v, -1);
        vector<int> ans;
        
        for(int i = 0; i < v; i++)
        {
            if(vis[i] == -1) dfs(adj, i, vis);
            
            if(vis[i] == 1) ans.push_back(i);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
