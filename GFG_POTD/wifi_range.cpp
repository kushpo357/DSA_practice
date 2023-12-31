//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
        // code here
        int r = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 49) r = x;
            else if(r) 
            {
                s[i] = 50;
                r--;
            }
        }
        for(int i = n - 1; i >= 0; i--)
        {
           if(s[i] == 49) r = x;
            else if(r) 
            {
                s[i] = 50;
                r--;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 48) return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends