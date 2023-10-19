//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int v, vector<int> adj[], int x) 
	{
	    // code here
	    int level = 0;
	    vector<bool> vis(v, 0);
	    queue<int> q;
	    q.push(0);
	    vis[0] = 1;
	    {
	        int n = q.size();
	        while(n--)
	        {
	            int temp = q.front();
	            q.pop();
	            if(temp == x) return level;
	            
	            for(int i = 0; i < adj[temp].size(); i++)
	            {
	                if(!vis[adj[temp][i]])
	                {
	                    vis[adj[temp][i]] = 1;
	                    q.push(adj[temp][i]);
	                }
	            }
	        }
	        level++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends
