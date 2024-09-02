//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    // Function to check if a cell is within grid bounds
    bool isvalid(int i, int j, int row, int col) {
        if (i < 0 || j < 0 || i >= row || j >= col) return false;
        return true;
    }

    // Function to return the minimum cost to reach the bottom-right cell from the top-left cell
    int minimumCostPath(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        dist[0][0] = grid[0][0];

        // Min-heap to store the current minimum cost and the corresponding cell coordinates
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({dist[0][0], {0, 0}});

        // Directions for moving up, down, left, and right
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int cost = p.first;
            int i = p.second.first;
            int j = p.second.second;

            // If we reached the bottom-right corner, return the cost
            if (i == row - 1 && j == col - 1) break;

            // Explore neighboring cells
            for (int k = 0; k < 4; ++k) {
                int xdx = i + dx[k];
                int ydy = j + dy[k];

                if (isvalid(xdx, ydy, row, col)) {
                    if (dist[xdx][ydy] > dist[i][j] + grid[xdx][ydy]) {
                        dist[xdx][ydy] = dist[i][j] + grid[xdx][ydy];
                        pq.push({dist[xdx][ydy], {xdx, ydy}});
                    }
                }
            }
        }

        return dist[row - 1][col - 1];
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
