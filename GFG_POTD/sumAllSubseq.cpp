//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        
        long long prev_res = s[0] - '0', mod = 1e9+7;
        long long res = prev_res, sub_res;
        for(int i = 1; i < s.size(); i++){
            sub_res = ((i+1)*(s[i] - '0') + 10 * prev_res)%mod;
            res = (res + sub_res)%mod;
            prev_res = sub_res;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends
