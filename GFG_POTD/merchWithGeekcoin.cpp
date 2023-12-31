//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    
    int isPossible(int n , int coins[]) 
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(coins[i] % 20 == 0 || coins[i] % 24 == 0) return 1;
            sum += coins[i];
        }
        
        if(sum == 2024) return 1;
        
        vector<vector<bool>> mod20(n + 1, vector<bool>(20, 0));
        
        for(int i = n - 1; i >= 0; i--)
        {
            mod20[i][coins[i] % 20] = 1;
            for(int j = 20; j >= 0; j--)
            {
                if(mod20[i + 1][j])
                {
                    mod20[i][j] = mod20[i + 1][j];
                    if((coins[i] + j) % 20 == 0) return 1;
                    
                    mod20[i][(coins[i] + j) % 20] = 1;
                }
            }
        }
        
        vector<vector<bool>> mod24(n + 1, vector<bool>(24, 0));
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 24; j >= 0; j--)
            {
                if(mod24[i + 1][j])
                {
                    if((coins[i] + j) % 24 == 0) return 1;
                    
                    mod24[i][j] = mod24[i + 1][j];
                    mod24[i][(coins[i] + j) % 24] = 1;
                }
            }
        }
        
        return 0;
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends
