//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        vector<int> v(26, 0);
        int n = s.size();
        
        for(int i = 0; i < n; i++) v[s[i] - 97]++;
            
        int mini = min(v['a' - 97], v['b' - 97]);
        mini = min(min(v['l' - 97]/2, v['o' - 97]/2), min(mini, v['n' - 97]));
        
        return mini;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends