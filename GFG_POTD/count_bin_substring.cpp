//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
  long long countSubstring(string s){
    // code here
    int count = 0;
    long long ans = 0;
    int n = s.size();
    
    vector<long long> fre(2*n + 2, 0);
    vector<long long> dp(2*n + 2, 0);
    
    fre[n]++;
    
    for(char c : s)
    {
        if(c == '0') count--;
        else count++;
        
        if(count - 1 + n >= 0)
            dp[count + n] = dp[count - 1 + n] + fre[count - 1 + n];
            
        ans += dp[count + n];
        fre[count + n]++;
    }
    
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    string S;
    cin>>S;
    Solution obj;
    long long ans =obj.countSubstring(S);
    cout<<ans<<endl;
 }
}
// } Driver Code Ends