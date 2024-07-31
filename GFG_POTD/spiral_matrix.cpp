//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code her
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> ans;
        
        int rs = 0, re = n - 1, cs = 0, ce = m - 1;
        
        while(cs <= ce && rs <= re)
        {
            for(int i = cs; i <= ce; i++)
            {
                ans.push_back(mat[rs][i]);
            }
            rs++;
            
            if(rs > re)
                break;
            
            for(int i = rs; i <= re; i++)
            {
                ans.push_back(mat[i][ce]);
            }
            ce--;
            
            if(cs > ce)
                break;
            
            for(int i = ce; i >= cs; i--)
            {
                ans.push_back(mat[re][i]);
            }
            re--;
            
            if(rs > re)
                break;
                
            for(int i = re; i >= rs; i--)
            {
                ans.push_back(mat[i][cs]);
            }
            cs++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
