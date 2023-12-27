//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> mat) 
    {
        // Code here
        vector<int> ans;
        int n = mat.size();
        int col = 0;
        for(int j = 0; j < n; j++)
        {
            int i = 0;
            while(j >= i)
            {
                ans.push_back(mat[i][j - i]);
                i++;
            }
        }
        
        for(int i = 1; i < n; i++)
        {
            int k = i;
            int j = n - 1;
            while(k < n)
            {
                ans.push_back(mat[k][j]);
                j--;
                k++;
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
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
