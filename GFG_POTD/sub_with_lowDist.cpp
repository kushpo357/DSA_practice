//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string S, int K) {
        //code here
        
        int ans = 0, dist = 0, n = S.size();
        
        
        vector<int> fre(26, 0);
        for(int i = 0; i < K; i++)
        {
            fre[S[i]-'a']++;
            if(fre[S[i]-'a']==1)
                dist++;    
        }
        
        
        if(dist==K-1)
            ans++;
           
        
        for(int i = K; i < n; i++)
        {
            fre[S[i-K]-'a']--;
            if(fre[S[i-K]-'a']==0)
                dist--;
            fre[S[i]-'a']++;
            if(fre[S[i]-'a']==1)
                dist++;
                
            if(dist==K-1)
                ans++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends