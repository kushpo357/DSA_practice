//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#include <vector>
#include <unordered_map>

class Solution {
public:
    int dfs(unordered_map<int, vector<int>>& mp, int u, int parent, int& ans) 
    {
        int count = 1;
        for (auto& i : mp[u])
        {
            if (i != parent) 
            {
                int subtree = dfs(mp, i, u, ans);
                if(!(subtree&1))
                    ans++;
                else
                    count++;
            }
        }
        return count;
    }
    
    int minimumEdgeRemove(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            mp[v].push_back(u);
            mp[u].push_back(v);
        }
        
        int ans = 0;
        
        dfs(mp, 1, -1, ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends
