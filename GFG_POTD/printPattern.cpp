//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(vector<int> &ans, int n, int &curr, bool &decrease)
    {
        if(curr == n && !decrease) return;
        
        if(curr <= 0) 
        {
            decrease = false;
        }
        
        if(decrease)
        {
            curr -= 5;
        }
        else
        {
            curr += 5;
        }
        
        ans.push_back(curr);
        
        solve(ans, n, curr, decrease);
    }
    vector<int> pattern(int n){
        // code here
        
        if(n <= 0) return {n};
        vector<int> ans;
        ans.push_back(n);
        //n -= 5;
        
        bool decrease = true;
        int curr = n;
        solve(ans, n, curr, decrease);
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
