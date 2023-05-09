//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    #define MOD 1000000007
    vector<vector<long long>> multi(vector<vector<long long>> &m1, vector<vector<long long>> &m2)
    {
        vector<vector<long long>> mat(2, vector<long long>(2, 0));
        for(int i = 0; i < 2 ; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                int temp = 0;
                for(int k = 0; k < 2; k++)
                {
                    temp = (temp % MOD + (m1[i][k]*m2[k][j]) % MOD) % MOD;
                }
                mat[i][j] = temp % MOD;
            }
        }
        return mat;
    }
    vector<vector<long long>> matrixexp(long long len, vector<vector<long long>> &v)
    {
        if(len == 1) return v;
        vector<vector<long long>> m1 = matrixexp(len/2, v);
        vector<vector<long long>> r = multi(m1, m1);
        
        if(len & 1) r = multi(r, v);
        
        return r;
    }
    int countStrings(long long int n) {
        // Code here
        vector<vector<long long>> v = {{1, 1}, {1, 0}};
        
        vector<vector<long long>> ans = matrixexp(n, v);
        
        return (ans[1][0] + ans[0][0]) % MOD;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}
// } Driver Code Ends