//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(vector<vector<int>> &arr,int num, int j, int k, int n, int m)
    {
        if(j> n - 1 || k > m - 1 || j < 0 || k < 0)
            return;
            
        if(arr[j][k] != num)
            return;
            
        arr[j][k]+=1;
        
        dfs(arr, num, j - 1, k, n, m);
        dfs(arr, num, j + 1, k, n, m);
        dfs(arr, num, j, k - 1, n, m);
        dfs(arr, num, j, k + 1, n, m);
        
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        int num = 1, K = operators.size();
        
        vector<int> ans;
        
        vector<vector<int>> arr(n,vector<int>(m,0));
        for(int i = 0; i < K ; i++)
        {
            int count = 0;
            arr[operators[i][0]][operators[i][1]] = num;
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < m; k++)
                {
                   if(arr[j][k] == num)
                    {    
                        dfs(arr, num, j, k, n, m);
                        count++;
                    }
                }
            }
            ans.push_back(count);
            num++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends