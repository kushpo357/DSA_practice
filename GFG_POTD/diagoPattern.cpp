//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution {
public:
    vector<int> matrixDiagonally(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();

        for (int sum = 0; sum < n + n - 1; ++sum) {
            if (sum % 2 == 0) {
                for (int i = min(sum, n - 1); i >= max(0, sum - n + 1); --i) {
                    ans.push_back(mat[i][sum - i]);
                }
            } else {
                for (int i = max(0, sum - n + 1); i <= min(sum, n - 1); ++i) {
                    ans.push_back(mat[i][sum - i]);
                }
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends
