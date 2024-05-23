//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    //function to find the largest common subsequence
    int lcs(string &a, string &b)
    {
        int n = a.size();
        
        //dp to find lcs
        vector<vector<int>> dp(n + 1,vector<int>(n + 1,0));
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                
                if(a[i] == b[j])
                {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
                }
            }
        }
        
        return dp[0][0];
    }
    int kPalindrome(string str, int n, int k)
    {
        // code here
        string revstr = str;
        
        //making a reverse string to check largest subsequence which is same from both sides
        reverse(revstr.begin(), revstr.end());
        
        //finding largest palindromic subsequence
        int temp = lcs(revstr, str);
        
        //finding min elements to be removed to make str a palindrome
        int check = str.size() - temp;
        
        //finding if min elements to make str palindrome is less then k or not
        if(check <= k) 
            return 1;
            
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
