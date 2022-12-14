//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        // code here
        vector<int> res(2);
        int gmax = INT_MIN;
        int lmax = 0, l = 0, r = 0;
        for(int i = 0; i < n; i++)
        {
            int num = str[i] == '0' ? 1 : -1;
            
            if(num > num + lmax)
            {
                l = i;
                r = i;
                lmax = num;
            }
            else
            {
                r = i;
                lmax += num;
            }
            if(gmax < lmax)
            {
                res[0] = l + 1;
                res[1] = r + 1;
                gmax = lmax;
            }
        }
        if(gmax < 0)
            return {-1};
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends