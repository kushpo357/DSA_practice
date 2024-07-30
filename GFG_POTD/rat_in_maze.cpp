//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    void solve(vector<vector<int>> &mat, const int &n, int i, 
        int j, vector<vector<bool>> &vis, string &s, vector<string> &ans)
    {
        if(vis[i][j])
        {    
            s.pop_back();
            return;
        }
        
        if(i == n - 1 && j == n - 1)
        {
            ans.push_back(s);
            s.pop_back();
            return;
        }
        
        vis[i][j] = 1;
        
        if((j > 0) && (mat[i][j - 1] == 1))
        {
            s.push_back('L');
            solve(mat, n, i, j - 1, vis, s, ans);
        }
        
        if((j < n - 1) && (mat[i][j + 1] == 1))
        {
            s.push_back('R');
            solve(mat, n, i, j + 1, vis, s, ans);
        }
        
        if((i < n - 1) && (mat[i + 1][j] == 1))
        {
            s.push_back('D');
            solve(mat, n, i + 1, j, vis, s, ans);
        }
        
        if(i > 0 && mat[i - 1][j])
        {
            s.push_back('U');
            solve(mat, n, i - 1, j, vis, s, ans);
        }
        
        s.pop_back();
        vis[i][j] = false;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        
        int n = mat.size();
        
        if(!mat[0][0])
            return {};
            
        vector<vector<bool>> vis(n, vector<bool>(n , 0));
        
        vector<string> ans;
        
        string s;
        solve(mat, n, 0, 0, vis, s, ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
