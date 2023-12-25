//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int>> mat, int n)
    {
        // code here
        if(n == 1) return mat[0][0];
        if(n == 2) return (mat[0][0]* mat[1][1] - mat[0][1]* mat[1][0]);
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            vector<vector<int>> tempmat(n - 1, vector<int> (n - 1, 0));
            for(int j = 1; j < n; j++)
            {
                int tempj = 0;
                for(int k = 0; k < n; k++)
                {
                    if(k == i) continue;
                    tempmat[j - 1][tempj++] = mat[j][k];
                }
            }
            ans += pow(-1, i)*mat[0][i]*determinantOfMatrix(tempmat, n - 1);
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
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends
