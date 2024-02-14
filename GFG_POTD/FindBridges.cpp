//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
private:

vector<int> parent;
vector<int> low;
vector<int> disc;
vector<bool> vis;

public:

    void solve(int &timer, int node, vector<vector<int>> &ans, vector<int> adj[])
    {
        vis[node] = 1;
        disc[node] = timer;
        low[node] = timer;
        timer++;
        int n = adj[node].size();
        for(int i = 0; i < n; i++)
        {
            if(adj[node][i] == parent[node]) continue;
            if(vis[adj[node][i]] == 1)
            {
                low[node] = min(low[node], low[adj[node][i]]);
            }
            else
            {
                parent[adj[node][i]] = node;
                
                solve(timer, adj[node][i], ans, adj);
                low[node] = min(low[node], low[adj[node][i]]);
                if(low[adj[node][i]] > disc[node]) 
                    ans.push_back({min(node, adj[node][i]), max(node, adj[node][i])});
            }
        }
        timer--;
    }
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
	    // Code here
	    vector<vector<int>> ans;
	    parent.resize(v, -1);
	    vis.resize(v, 0);
	    low.resize(v, -1);
	    disc.resize(v, -1);
	    int timer = 0;
	    solve(timer, 0, ans, adj);
	    sort(ans.begin(), ans.end());
	    
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
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends
