//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isValid(int n, int m, int i, int j, vector<vector<char>> &mat)
    {
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        if(mat[i][j] == 'O') return true;
        return false;
    }
    void dfsMakeP(int n, int m, int i, int j, vector<vector<char>> &mat)
    {
        mat[i][j] = 'P';
        if(isValid(n, m, i, j + 1, mat))
            dfsMakeP(n, m, i, j + 1, mat);
        if(isValid(n, m, i, j - 1, mat))
            dfsMakeP(n, m, i, j - 1, mat);
        if(isValid(n, m, i + 1, j, mat))
            dfsMakeP(n, m, i + 1, j, mat);
        if(isValid(n, m, i - 1, j, mat))
            dfsMakeP(n, m, i - 1, j, mat);
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        
        for(int j = 0; j < m; j++)
        {
            if(mat[0][j] == 'O') dfsMakeP(n, m, 0, j, mat);
            if(mat[n - 1][j] == 'O') dfsMakeP(n, m , n - 1, j, mat);
        }
        for(int i = 0; i < n; i++)
        {
            if(mat[i][0] == 'O') dfsMakeP(n, m, i, 0, mat);
            if(mat[i][m - 1] == 'O') dfsMakeP(n, m, i , m - 1, mat);
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 'P') mat[i][j] = 'O';
                else mat[i][j] = 'X';
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
