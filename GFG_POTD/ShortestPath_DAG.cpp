//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  
  public:
  void topoSort(vector<int> &vis, vector<vector<pair<int,int>>> &adj, stack<int> &st, int node)
    {
        vis[node]=1;
        
        for(auto it:adj[node])
        {
            int v = it.first;
            if(vis[v]==0) topoSort(vis,adj,st,v);
        }
        st.push(node);
    }
    
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
         // code here
        
        vector<vector<pair<int,int>>> adj(n);
        
        for(int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
        }
        
        vector<int> vis(n, 0);
        stack<int> st;
        
        for(int i = 0; i < n; i++)
            if(!vis[i]) topoSort(vis,adj,st,i);
        
        vector<int> dis(n,INT_MAX);
        
        dis[0] = 0;
        
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            for(auto it:adj[node])
            {
                int v = it.first;
                int wt = it.second;
                
                if(dis[node] + wt < dis[v] && dis[node] != INT_MAX)
                    dis[v] = dis[node]+wt;
            }
        }
        
        for(int i = 0; i < dis.size(); i++)
            if(dis[i] == INT_MAX) dis[i] = -1;
                
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends