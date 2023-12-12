//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> mat)
    {
        // code here
        
        for(int j = m - 2; j >= 0; j--)
        {
            if(n > 1) mat[0][j] += max(mat[0][j + 1], mat[1][j + 1]);
            else mat[0][j] += mat[0][j + 1];
            
            if(n > 1) mat[n - 1][j] += max(mat[n - 1][j + 1], mat[n - 2][j + 1]);
            
            for(int i = 1; i < n - 1; i++)
            {
                int temp = max(mat[i][j + 1], mat[i - 1][j + 1]);
                temp = max(mat[i + 1][j + 1], temp);
                
                mat[i][j] += temp;
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) ans = max(ans, mat[i][0]);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
