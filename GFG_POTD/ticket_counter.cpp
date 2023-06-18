//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int n, int k) {
        // code here
        
        int ndivk = n/k, nremk = n%k;
        
        if(!nremk)
        {
            if(ndivk&1) return ((ndivk + 1)/2)*k;
            return n/2 + 1;
        }
        
        if(ndivk & 1) return n - ((ndivk)/2)*k - nremk + 1;
        return ((ndivk + 1)/2)*k + nremk;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends