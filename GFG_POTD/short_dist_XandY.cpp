//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        // code here
        int ans = INT_MAX;
      
        vector<pair<int,int>> vx;
        vector<pair<int,int>> vy;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 'X')
                    vx.push_back({i,j});
                else if(grid[i][j] == 'Y')
                    vy.push_back({ i, j});
            }
        }
        
        for(int i = 0; i < vx.size();i++)
        {
            for(int j=0;j<vy.size();j++)
            {
                ans = min(ans, abs(vx[i].first - vy[j].first) + abs(vx[i].second - vy[j].second));
                if(ans == 1)
                    return 1;
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
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends