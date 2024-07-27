//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str)
    {
        //complete the function here
        
        int n = str.size();
        
        string revstr = str;
        reverse(revstr.begin(), revstr.end());
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                
                if(str[i] == revstr[j])
                {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
                }
            }
        }
    
        return n - dp[0][0];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends
