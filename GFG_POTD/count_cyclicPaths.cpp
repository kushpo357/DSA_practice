//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    
    int countPaths(int n){
        // code here 
        int mod = 1e9 + 7;
        
        long long cur[] = {1, 0, 0, 0}, prev[] = {1, 0, 0, 0};
        
        for(int i = 0; i < n; i++)
        {
            cur[0] = (prev[1]%mod + prev[2]%mod + prev[3]%mod) % mod;
            cur[3] = (prev[1]%mod + prev[2]%mod + prev[0]%mod) % mod;
            cur[1] = (prev[0]%mod + prev[2]%mod + prev[3]%mod) % mod;
            cur[2] = (prev[1]%mod + prev[0]%mod + prev[3]%mod) % mod;
            
            prev[0] = cur[0];
            prev[1] = cur[1];
            prev[2] = cur[2];
            prev[3] = cur[3];
        }
        
        return (int)prev[0];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends