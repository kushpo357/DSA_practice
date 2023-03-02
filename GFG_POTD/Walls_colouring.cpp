//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int n=costs.size(),m=costs[0].size();
        
        if(n>1 and m==1) 
            return -1;
            
        int f_min=INT_MAX, s_min=INT_MAX, f_ind=-1;
        
        for(int i=0; i<1; ++i)
        {
            
            for(int j=0; j<m; ++j) 
            {
                if(costs[i][j]<f_min)
                {
                    f_min=costs[i][j];
                    f_ind=j;
                }
            }
            
            for(int j=0; j<m; ++j)
            {
                if(costs[i][j]<s_min and j!=f_ind)
                    s_min=costs[i][j];
            }
        }
        
        for(int i=1; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(j!=f_ind) 
                    costs[i][j]=f_min+costs[i][j];
                else 
                    costs[i][j]=s_min+costs[i][j];
            }
            
            f_min=INT_MAX, s_min=INT_MAX, f_ind=-1;
            
            for(int j=0; j<m; ++j)
            {
                if(costs[i][j]<f_min)
                {
                    f_min=costs[i][j];
                    f_ind=j;
                }
            }

            for(int j=0; j<m; ++j) 
            {
                if(costs[i][j]<s_min and j!=f_ind)
                {
                    s_min=costs[i][j];
                }
            }
        }
        return f_min;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends