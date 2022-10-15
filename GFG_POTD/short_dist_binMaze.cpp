//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int ans = 0;
        queue<pair<int, int>> que;
        grid[source.first][source.second] = 0;
        que.push(source);
        while(!que.empty())
        {
            int count = que.size();
            for(int i = 0; i < count; i++)
            {
                pair<int, int> curr = que.front();
                que.pop();
                if(curr.first == destination.first && curr.second == destination.second)
                    return ans;
                
                if(curr.first - 1 >= 0)
                {
                    if(grid[curr.first - 1][curr.second] == 1)
                    {
                        grid[curr.first - 1][curr.second] = 0;
                        que.push({curr.first - 1,curr.second});
                    }
                }
                
                if(curr.second - 1 >= 0)
                {
                    if(grid[curr.first][curr.second - 1] == 1)
                    {
                        grid[curr.first][curr.second - 1] = 0;
                        que.push({curr.first,curr.second - 1});
                    }
                }
                
                if(curr.first + 1 < grid.size())
                {
                    if(grid[curr.first + 1][curr.second] == 1)
                    {
                        grid[curr.first + 1][curr.second] = 0;
                        que.push({curr.first + 1,curr.second});
                    }
                }
                
                if(curr.second + 1 < grid[0].size())
                {
                    if(grid[curr.first][curr.second + 1] == 1)
                    {
                        grid[curr.first][curr.second + 1] = 0;
                        que.push({curr.first,curr.second + 1});
                    }
                }
                
            }
            ans++;
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends