//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int n = s.size(), ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            vector<int> fre(26,0);
            for(int j = i; j < n; j++)
            {
                fre[s[j] - 'a']++;
                ans += getbeauty(fre);
            }
        }
        return ans;
    }
    
    int getbeauty(vector<int> fre)
    {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i = 0; i < fre.size(); i++)
        {
            if(fre[i] == 0)
                continue;
            mini = min(mini, fre[i]);
            maxi = max(maxi, fre[i]);
        }
        return maxi - mini;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends