//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string S, int k) {
        // code here 
        unordered_map<char,int> mp ;
        
        int i = 0 ;
        int n = S.length() ; // 4
        
        while( i < k-1 ) // 
        {
            mp[S[i]]++ ;
            i++ ;
        }
        
        int cnt = 0 ;
        while( i < n )
        {
            mp[S[i]]++ ;
            
            if( mp.size() == k-1 )
            {
                cnt++ ;
            }
            
            mp[S[i-(k-1)]]-- ; 
            if( mp[S[i-(k-1)]] == 0 ) 
            {
                mp.erase( S[i-(k-1)] ) ;
            }
            i++ ;
        }
        
        return cnt ;
        
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