//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void dfs(int vertex, vector<vector<int>> &paths, const int &n, vector<bool> &vis)
    {
        vis[vertex] = 1;
        for(int i = 0; i < n; i++)
        {
            if(paths[vertex][i] == 1)
            {
                paths[vertex][i] = 2;
                if(vis[i] == 0)
                    dfs(i, paths, n, vis);
            }
        }
    }
	int isPossible(vector<vector<int>>paths){
	    // Code here
	    
	    int numberOfEdges = 0;
	    int n = paths.size();
	    int dfsVertex = -1;
	    for(int i = 0; i < n; i++)
	    {
	        int Edges = 0;
	        for(int j = 0; j < n; j++)
	        {
	            if(i == j) continue;
	            if(paths[i][j] == 1) 
	            {
	                if(dfsVertex == -1) dfsVertex = i;
	                numberOfEdges++;
	                Edges++;
	            }
	        }
	        
	        if(Edges & 1) return 0;
	    }
        
        
        if(dfsVertex == -1) return 1;
        numberOfEdges = numberOfEdges/2;
        
        vector<bool> vis(n, 0); 
        dfs(dfsVertex, paths, n, vis);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(paths[i][j] == 1) return 0;
            }
        }
        
        return 1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
