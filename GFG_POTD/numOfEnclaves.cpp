//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    bool isvalid( int n, int m, int i, int j)
    {
        if(i >= n || j >= m || i < 0 || j < 0) return 0;
        
        return 1;
    }
    
    void dfs(vector<vector<int>> &grid, int n, int m, int i, int j)
    {
        grid[i][j] = 0;
        if(isvalid(n, m, i - 1, j) && grid[i - 1][j]) dfs(grid, n, m, i - 1, j);
        if(isvalid(n, m, i + 1, j) && grid[i + 1][j]) dfs(grid, n, m, i + 1, j);
        if(isvalid(n, m, i, j + 1) && grid[i][j + 1]) dfs(grid, n, m, i, j + 1);
        if(isvalid(n, m, i, j - 1) && grid[i][j - 1]) dfs(grid, n, m, i, j - 1);
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++)
        {
            if(grid[i][0]) dfs(grid, n, m, i, 0);
            if(grid[i][m - 1]) dfs(grid, n, m, i, m - 1);
        }
        
        for(int j = 0; j < m; j++)
        {
            if(grid[0][j]) dfs(grid, n, m, 0, j);
            if(grid[n - 1][j]) dfs(grid, n, m, n - 1, j);
        }
        
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j]) count++;
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
