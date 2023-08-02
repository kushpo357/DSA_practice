//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool valid(vector<vector<int>> &arr, int n, int m, vector<vector<bool>> &vis, int r, int c)
    {
        if(r < 0 || r >= n || c < 0 || c >= m || vis[r][c] || arr[r][c] == 0) return 0;
        vis[r][c] = 1;
        return 1;
    }
    int shortestDistance(int n, int m, vector<vector<int>> arr, int X, int Y) {
        // code here
        if(X >= n || Y >= m || !arr[0][0] || !arr[X][Y]) return -1;
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        queue<vector<int>> q;
        q.push({0, 0, 0});
        while(!q.empty())
        {
            auto u = q.front();
            q.pop();
            if(u[0] == X && u[1] == Y) return u[2];
            if(valid(arr, n, m, visited, u[0] - 1, u[1]))
                q.push({u[0] - 1, u[1], u[2] + 1});
            if(valid(arr, n, m, visited, u[0] + 1, u[1]))
                q.push({u[0] + 1, u[1], u[2] + 1});
            if(valid(arr, n, m, visited, u[0], u[1] - 1))
                q.push({u[0], u[1] - 1, u[2] + 1});
            if(valid(arr, n, m, visited, u[0], u[1] + 1))
                q.push({u[0], u[1] + 1, u[2] + 1});
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends