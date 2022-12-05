//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        vector<vector<int>> vis(n, vector<int> (m, -1));
        queue<vector<int>> q;
        q.push({0,0,0,k});
        
        while(!q.empty())
        {
            auto temp = q.front();
            int x = temp[0], y = temp[1];
            q.pop();
            
            if(x < 0 || y < 0 || x >= n || y >= m)
                continue;
                
            if(x == n - 1 && y == m - 1)
                return temp[2];
                
            if(mat[x][y] == 1)
            {
                if(temp[3] > 0)
                    temp[3]--;
                else
                    continue;
            }
            
            if(vis[x][y] != -1 && vis[x][y] >= temp[3])
                continue;
            
            vis[x][y] = temp[3];
            
            q.push({x - 1, y, temp[2] + 1, temp[3]});
            q.push({x + 1, y, temp[2] + 1, temp[3]});
            q.push({x, y - 1, temp[2] + 1, temp[3]});
            q.push({x, y + 1, temp[2] + 1, temp[3]});
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends