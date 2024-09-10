//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<int> & vis, int u, vector<vector<int>> &adj)
    {
        vis[u] = true;
        for(auto v : adj[u])
        {
            if(vis[v] == false)
              dfs(vis, v, adj);
        }
    }
    bool Solve(vector<int> & mark, int src, vector<vector<int>> &adj)
    {
        vector<int> vis(26, 0);
        dfs(vis, src, adj);
        for(int i = 0; i < 26; i++)
        {
            if(vis[i] == false && mark[i] == true)
            return false;
        }
        return true;
    }
    int isCircle(vector<string> &arr) {
        //Code here
        
        vector<vector<int>> adj(26);
        vector<int> indeg(26, 0);
        vector<int> outdeg(26, 0);
        
        int src = INT_MAX;
        vector<int> mark(26, 0);
        int n = arr.size();
        
        for(int i = 0;i < n; i++)
        {
            string str = arr[i];
            int u = int(str[0] - 'a');
            int v = int(str.back() - 'a');
            indeg[u]++;
            outdeg[v]++;
            
            if(!i) src = u;
            
            adj[u].push_back(v);
            mark[v] = 1;
            mark[u] = 1;
        }
        
        if(indeg != outdeg)
            return 0;
            
        return Solve(mark, src, adj);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends
