//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


bool isvalid(int i, int j, int r, int c)
{
    if(i < 0 || i >= r || j < 0 || j >= c) return false;
    
    return true;
}
void dfs(int i, int j, int r, int c, vector<vector<int>> &mat, int &ans)
{
    if(isvalid(i, j, r, c, mat, ans))
    
    if(mat[i][j] == 0) return ans;
}
class Solution
{
public:

    
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
       int r = mat.size();
       int c = mat[0].size();
      vector<<vector<int>> vis(r, vector<int> (c, -1));
       
       
       for(int i = c; i >= 0; i--)
       {
           for(int j = 0; j < r; j++)
           {
               if(vis[i][j] != -1) continue;
               
               if(mat[i][j] == 0)
               {
                   if(isvalid(i + 1, j, r, c))
                   {
                       vis[i + 1][j] = INT_MAX;
                   }
                   if(isvalid(i - 1, j, r, c))
                   {
                       vis[i - 1][j] = INT_MAX;
                   }
                   if(isvalid(i, j - 1, r, c))
                   {
                       vis[i][j - 1] = INT_MAX;
                   }
                   if(isvalid(i, j + 1, r, c))
                   {
                       vis[i][j + 1] = INT_MAX;
                   }
               }
           }
       }
       
       int ans = INT_MAX;
       dfs(0, 0, r, c, mat, ans);
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
