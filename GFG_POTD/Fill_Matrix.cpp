//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    
    int dist(int i, int j, int x, int y)
    {
        return abs( i - x ) + abs( j - y );
    }
    
    int minIteration(int n, int m, int x, int y){
        
        int ans = 0;
        
        for(int i = 1; i <= n; i++) 
        {
            for(int j = 1; j <= m; j++)
                ans = max( ans, dist( i , j , x , y ) );
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends