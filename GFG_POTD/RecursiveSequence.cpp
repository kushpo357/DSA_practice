//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:

#define MOD 1000000007
    long long sequence(int n){
        // code here
        
        long long ans = 0;
        int num = 1;
        for(int i = 0; i < n; i++)
        {
            long long currnum = 1;
            for(int j = 0; j <= i; j++)
            {
                currnum = (currnum*num)%MOD;
                
                num++;
            }
            //cout<<currnum<<endl;
            ans = ((ans % MOD) + (currnum%MOD))%MOD;
        }
        
        return ans%MOD;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
