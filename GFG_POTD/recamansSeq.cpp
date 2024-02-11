//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        vector<int> ans;
        set<int> s;
        ans.push_back(0);
        for(int i = 1; i < n; i++)
        {
            if(ans.back() - i > 0 && s.find(ans.back() - i) == s.end())
            {
                ans.push_back(ans.back() - i);
            }
            else ans.push_back(ans.back() + i);
            s.insert(ans.back());
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
