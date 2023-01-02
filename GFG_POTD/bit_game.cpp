//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int swapBitGame(long long n){
        // code here
        int ans = 0;
        
        while(n)
        {
            int temp = n & 1;
            
            if(temp)
                ans++;
            
            n = n >> 1;
        }
        
        if(ans & 1)
            return 1;
        else
            return 2;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.swapBitGame(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends