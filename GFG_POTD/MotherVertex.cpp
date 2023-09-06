//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int i, vector<int> adj[], vector<bool> &vis, vector<int> &topo)
    {
        vis[i] = 1;
        for (auto edge : adj[i]) 
        {
            if (!vis[edge])
                dfs(edge, adj, vis, topo);
        }
        topo.push_back(i);
    }
	int findMotherVertex(int v, vector<int>adj[])
	{
	    // Code here
	    vector<bool> vis(v, 0);
	    vector<int> topo;
        for (int i = 0; i < v; ++i) 
        {
            if (!vis[i])
                dfs(i, adj, vis, topo);
        }
        for(int i = 0; i < v; i++) vis[i] = 0;
        if (topo.size() == v) 
        {
            int ans = topo.back();
            topo.clear();
            dfs(ans, adj, vis, topo);
            
            if (topo.size() == v) return ans;
        }
        
        return -1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
