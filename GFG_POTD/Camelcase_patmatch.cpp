//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  #include <ctype.h>
    
    vector<string> CamelCase(int n, vector<string> dict, string pat) {
        // code here
        
        vector<string> ans;
        int patlen = pat.size();
        for(int i = 0; i < n; i++)
        {
            int ind = 0;
            int len = dict[i].size();
            for(int j = 0; j < len; j++)
            {
                if(isupper(dict[i][j]))
                {
                    if(dict[i][j] == pat[ind]) ind++;
                    else break;
                    if(ind == patlen)
                    {
                        ans.push_back(dict[i]);
                        break;
                    }
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        
        if(ans.empty()) return {"-1"};
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends