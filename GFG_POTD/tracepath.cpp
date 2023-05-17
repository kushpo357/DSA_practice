//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        int len = s.size();
        int maxleft = 0, maxright = 0;
        int maxup = 0, maxdown = 0;
        int x = 0, y = 0;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == 'L')y--;
            else if(s[i] == 'R')y++;
            else if(s[i] == 'U') x++;
            else x--;
            
            maxleft = min(y, maxleft);
            maxright = max(y, maxright);
            maxup = max(x, maxup);
            maxdown = min(x, maxdown);
        }
        
        if((maxright - maxleft) < m && (maxup - maxdown) < n) return 1;
        
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends