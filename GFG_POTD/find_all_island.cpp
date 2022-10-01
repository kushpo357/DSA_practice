//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int rows = grid.size();
        if (rows == 0)
            return 0;
    
        int cols = grid[0].size();
        if (cols == 0)
            return 0;
    
        set<vector<pair<int, int> > > coordinates;
    
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
    
                if (grid[i][j] != 1)
                    continue;
    
                vector<pair<int, int> > v;
                dfs(grid, i, j, i, j, v);
    
                coordinates.insert(v);
            }
        }
    
        return coordinates.size();
    }
    
    vector<vector<int> > dirs = { { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };
    
    void dfs(vector<vector<int> >& grid, int x0, int y0, int i, int j, vector<pair<int, int> >& v){
        
        int rows = grid.size(), cols = grid[0].size();
    
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] <= 0)
            return;
    
        grid[i][j] *= -1;

        v.push_back({ i - x0, j - y0 });
    
        for (auto dir : dirs) {
            
            dfs(grid, x0, y0, i + dir[0], j + dir[1], v);
            
        }
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends