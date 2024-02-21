//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define ll long long 
int mod = 1000000007;

class Solution{
public:
    int countWays(int n, string S){
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll> (2, 0)));
        
        for(int i=0; i<n; i++){
            dp[i][i][1] = (S[i] == 'T');
            dp[i][i][0] = (S[i] == 'F');
        }
        
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                for(int isTrue=0; isTrue <=1; isTrue++){
                    ll ans=0;
                    for(int ind =i+1; ind <= j-1; ind=ind+2){
                        ll LT = dp[i][ind-1][1];
                        ll LF = dp[i][ind-1][0];
                        ll RT = dp[ind+1][j][1];
                        ll RF = dp[ind+1][j][0];
                        if(S[ind] == '&'){
                            if(isTrue) ans = (ans + (LT * RT)%mod)%mod;
                            else ans = (ans + (LT*RF)%mod + (LF*RF)%mod + (LF*RT)%mod)%mod;
                        }
                        else if(S[ind] == '|'){
                            if(isTrue) ans = (ans + (LT*RT)%mod + (LT*RF)%mod + (LF*RT)%mod)%mod;
                            else ans = (ans + (LF*RF)%mod)%mod;
                        }
                        else{
                            if(isTrue) ans = (ans + (LT*RF)%mod + (LF*RT)%mod)%mod;
                            else ans = (ans + (LT*RT)%mod + (LF*RF)%mod)%mod;
                        }
                    }
                    dp[i][j][isTrue] = ans % 1003;
                }
            }
        }
        return dp[0][n-1][1];
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
