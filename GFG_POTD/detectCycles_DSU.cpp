//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    
    int find_parent(vector<int> &parent, int a)
    {
        if(a == parent[a])
            return a;
            
        return parent[a] = find_parent(parent, parent[a]);
    }
	int detectCycle(int v, vector<int>adj[])
	{
	    // Code here
	    vector<int> parent(v, 0);
	    
	    for(int i = 0; i < v; i++) parent[i] = i;
	    
	    vector<int> size(v, 1);
	    
	    //int n = (sizeof(adj)/sizeof(adj[0]));
	    //cout<<n<<endl;
	    for(int i = 0; i < v; i++)
	    {
	        for(int j = 0; j < adj[i].size(); j++)
	        {
	            int u = i;
	            int v = adj[i][j];
	            
	            int x = find_parent(parent, u);
	            int y = find_parent(parent, v);
	            
	            //cout<<u<<' '<<v<<' '<<x<<' '<<y<<endl;
	            if(x == y && u < v) return 1;
	            else
	            {
	                if(size[x] < size[y])
	                    swap(x, y);
	                    
	                parent[y] = x;
	                size[x] += size[y];
	            }
	        }
	    }
	    
	    return 0;
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends
