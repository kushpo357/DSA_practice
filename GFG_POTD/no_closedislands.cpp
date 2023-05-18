//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    bool isvalid(int n, int m, int i, int j)
    {
        if(i < 0 || j < 0 || i >= n || j >= m) return 0;
        
        return 1;
    }
    void ifclosedisland(vector<vector<int>>& mat, int n, int m, int i, int j, int &isclosed, vector<vector<bool>> &isvis)
    {
        isvis[i][j] = 1;
        if(!i || !j || i == n - 1 || j == m - 1)
            isclosed = 0;
            
        if(isvalid(n, m, i - 1, j) && mat[i - 1][j] && !isvis[i - 1][j])
            ifclosedisland(mat, n, m, i - 1, j, isclosed, isvis);
        if(isvalid(n, m, i + 1, j) && mat[i + 1][j] && !isvis[i + 1][j])
            ifclosedisland(mat, n, m, i + 1, j, isclosed, isvis);
        if(isvalid(n, m, i, j - 1) && mat[i][j - 1] && !isvis[i][j - 1])
            ifclosedisland(mat, n, m, i, j - 1, isclosed, isvis);
        if(isvalid(n, m, i, j + 1) && mat[i][j + 1] && !isvis[i][j + 1])
            ifclosedisland(mat, n, m, i, j + 1, isclosed, isvis);
    }
    int closedIslands(vector<vector<int>>& mat, int n, int m) {
        // Code here
        vector<vector<bool>> isvis(n, vector<bool>(m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(isvis[i][j]) continue;
                if(!mat[i][j])
                {
                    isvis[i][j] = 1;
                    continue;
                }
                else
                {
                    int isclosed = 1;
                    ifclosedisland(mat, n, m, i, j, isclosed, isvis);
                    if(isclosed) ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends