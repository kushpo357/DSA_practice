//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToepliz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToepliz(a);
        if (n == 2 && m == 4) {
            cout << "0";
        } else {
            if (b == true)
                cout << "true";
            else
                cout << "false";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToepliz(vector<vector<int>>& mat) {
    // code here
    
    int n = mat.size(), m = mat[0].size();
    for(int i = m - 1; i >= 0; i--)
    {
        int val = mat[0][i];
        
        int ind = i;
        for(int j = 0; j < n && ind < m; ind++, j++)
        {
            if(val != mat[j][ind])
                return false;
        }
    }
    
    for(int i = 1; i < n; i++)
    {
        int val = mat[i][0];
        
        int ind = i;
        
        for(int j = 0; j < m && ind < n; ind++, j++)
        {
            if(val != mat[ind][j])
                return false;
        }
    }
    
    return true;
}
