//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void changedir(int dir, int &x, int &y)
    {
        switch(dir)
        {
            case 0: 
                y++;
                break;
            case 1:
                x++;
                break;
            case 2:
                y--;
                break;
            case 3:
                x--;
        }
    }
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& mat) {
        // Code here
        
        
        vector<int> ans;
        
        ans.push_back(0);
        ans.push_back(0);
        
        vector<int> curr;
        curr.push_back(0);
        curr.push_back(0);
        
        int dir = 0;
        while(curr[0] < n && curr[1] < m  && curr[0] >= 0 && curr[1] >= 0)
        {
            // cout<<curr[0]<<' '<<curr[1]<<endl;
            ans = curr;
            if(!mat[curr[0]][curr[1]])
                changedir(dir, curr[0], curr[1]);
            else
            {
                mat[curr[0]][curr[1]] = 0;
                dir = dir + 1;
                dir = dir % 4;
                changedir(dir, curr[0], curr[1]);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
