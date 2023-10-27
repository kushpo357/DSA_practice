//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
    
    int minimumNumberOfDeletions(string s) { 
        // code here
        
        int n = s.size();
        
        vector<int> curr(n + 1, 0), prev(n + 1, 0);
        
        for(int i = 0; i <= n; i++)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(s[i] == s[j])
                    curr[j] = 1 + prev[j + 1];
                else
                    curr[j] = max(prev[j], curr[j + 1]);
            }
            
            prev = curr;
        }
        
        return n - curr[0];
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends
