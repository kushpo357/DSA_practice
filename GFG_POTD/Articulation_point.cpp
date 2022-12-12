//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int node, int parent , vector<int> &vis, vector<int> &disc, vector<int> &low, int &timer, vector<int> adj[], vector<bool> &isArti )
    {
        vis[node] = 1;
        disc[node] = low[node] = timer++;
        int child = 0;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                child++;
                dfs(it, node, vis, disc, low, timer, adj, isArti);
                low[node] = min(low[node], low[it]);
                
                if(low[it] >= disc[node] && parent!= -1)
                    isArti[node] = true;
            }
            else if(it != parent)
                low[node] = min(low[node], disc[it]);
        }
        
        if(parent == -1 && child > 1)
            isArti[node] = 1;
    }
    
    vector<int> articulationPoints(int v, vector<int>adj[]) 
    {
        // Code here
        vector<int> ans;
        vector<int> disc(v, -1);
        vector<int> low(v, -1);
        vector<int> vis(v, 0);
        vector<bool> isArti(v, false);
        int timer = 0;
        
        for(int i = 0; i < v; i++)
            if(!vis[i]) dfs(i, -1, vis, disc, low, timer, adj, isArti);
        
        for(int i = 0; i < v; i++)
            if(isArti[i] == true) ans.push_back(i);
            
        if(ans.size() == 0)
            return {-1};
            
        return ans;
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
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends