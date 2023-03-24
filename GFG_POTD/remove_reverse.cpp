//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        // code here
        vector<int> f(26,0);
        for(int i = 0; i < s.length(); ++i)
            f[s[i] - 'a']++;
        
        int left = 0, right = s.length() - 1, rev = 0;
        string ans = s;
        
        while(left < right)
        {
            if(!rev)
            {
                int index = s[left] - 'a';
                if(f[index] > 1)
                {
                    rev = 1;
                    f[index]--;
                    ans[left] = '#';
                }
                
                left++;
            }
            else
            {
                int index = s[right] - 'a';
                if(f[index] > 1)
                {
                    rev = 0;
                    f[index]--;
                    ans[right] = '#';
                }
                
                right--;
            }
        }
        
        if(rev)
            reverse(ans.begin(), ans.end());
        
        string a = "";
        
        for(int i = 0; i < ans.size(); ++i){
            if(ans[i] != '#'){
                a.push_back(ans[i]);
            }
        }
        
        return a;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends