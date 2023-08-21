//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

    bool isvalid(int i, int j, int n, int m)
    {
        
        if(i < 0 || j < 0 || i >= n || j >= m) 
            return 0;
        
        return 1;
    }
    bool check(vector<vector<int>> &mat, int i, int j, int n, int m)
    {
        int count = 0;
        
        if(isvalid(i, j + 1, n, m) && !mat[i][j + 1]) count++;
        if(isvalid(i + 1, j, n, m) && !mat[i + 1][j]) count++;
        if(isvalid(i, j - 1, n, m) && !mat[i][j - 1]) count++;
        if(isvalid(i - 1, j, n, m) && !mat[i - 1][j]) count++;
        if(isvalid(i + 1, j + 1, n, m) && !mat[i + 1][j + 1]) count++;
        if(isvalid(i - 1, j + 1, n, m) && !mat[i - 1][j + 1]) count++;
        if(isvalid(i + 1, j - 1, n, m) && !mat[i + 1][j - 1]) count++;
        if(isvalid(i - 1, j - 1, n, m) && !mat[i - 1][j - 1]) count++;
        
        if(!count) return 0;
        
        return !(count & 1);
    }
    int Count(vector<vector<int>>& mat) {
        // Code here
        
        int ans = 0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] && check(mat, i, j, n, m)) ans++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
