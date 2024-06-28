//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        
        int n = arr.size();
        for(int itr = 0; itr < n; itr++)
        {
            int s = 0, e = n - 1;
            
            while(s <= e)
            {
                if(arr[itr][s] != arr[itr][e])
                break;
                
                s++;
                e--;
            }
            
            if(s > e)
            {
                string ans = "";
                ans.append(to_string(itr));
                ans.push_back(' ');
                ans.push_back('R');
                return ans;
            }
        }
        
        for(int itr = 0; itr < n; itr++)
        {
            int s = 0, e = n - 1;
            
            while(s <= e)
            {
                if(arr[s][itr] != arr[e][itr])
                break;
                
                s++;
                e--;
            }
            
            if(s > e)
            {
                string ans = "";
                ans.append(to_string(itr));
                ans.push_back(' ');
                ans.push_back('C');
                return ans;
            }
        }
        return "-1";
    }
};



//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends
