//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        vector<int> modfreq(k, 0);
        
        for(int i = 0; i < n; i++)
        {
            modfreq[nums[i] % k]++;
        }
        
        if(modfreq[0] & 1) return 0;
        if(k & 1 == 0 && (modfreq[k/2 + 1] & 1)) return 0;
        
        for(int i = 1; i <= k/2; i++)
        {
            if(modfreq[i] != modfreq[k - i]) return 0;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
