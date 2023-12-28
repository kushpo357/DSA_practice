//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    int dp[1000][1000];
    
    bool helper(string &wild, string &pattern, int wcurr, int pcurr){
        if(pcurr==pattern.size()){
            for(int i=wcurr;i<wild.size();i++){
                if(wild[i]!='*'){
                    return false;
                }
            }
            return true;
        }
        
        if(wcurr==wild.size()){
            return false;
        }
        
        if(dp[wcurr][pcurr]!=-1){
          return dp[wcurr][pcurr];
        }
        if(wild[wcurr]==pattern[pcurr] || wild[wcurr]=='?'){
            return dp[wcurr][pcurr]=helper(wild,pattern,wcurr+1,pcurr+1);
        }
        
        if(wild[wcurr]=='*'){
            return dp[wcurr][pcurr]=helper(wild,pattern,wcurr,pcurr+1) || helper(wild,pattern,wcurr+1,pcurr);
        }
        
        return dp[wcurr][pcurr]=false;
    }
    
    bool match(string wild, string pattern){
        memset(dp,-1,sizeof(dp));
        return helper(wild,pattern,0,0);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends
