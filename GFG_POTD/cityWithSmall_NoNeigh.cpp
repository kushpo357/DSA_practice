//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int, int>> adj[n];
        for(auto &vec : edges)
        {
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        for(int src=0; src<n; src++)
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
            pq.push({0, src});
            dist[src][src] = 0;
            while(!pq.empty())
            {
                int dis = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                
                for(auto &pr : adj[node])
                {
                    int adjNode = pr.first;
                    int edgeWeight = pr.second;
                    
                    if(dis!=INT_MAX && dis + edgeWeight < dist[src][adjNode])
                    {
                        dist[src][adjNode] = dis + edgeWeight;
                        pq.push({dist[src][adjNode], adjNode});
                    }
                }
                
            }
        }
        int ans = 0, minNbrs=INT_MAX;
        for(int i=0; i<n; i++)
        {
            int nbrs = 0;
            for(int j=0; j<n; j++)
            {
                if(i!=j && dist[i][j]<=distanceThreshold)
                {
                    nbrs++;
                }
            }
            
            if(nbrs < minNbrs)
            {
                minNbrs = nbrs;
                ans = i;
            }
            else if(nbrs == minNbrs)
            {
                ans = max(ans, i);
            }
        }
        return ans;
                     
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends
