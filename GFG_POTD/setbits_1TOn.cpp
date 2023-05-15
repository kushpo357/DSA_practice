//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long n) {
        // code here
        long long ans = 0;
        int num = 0;
        if(n & 1)
        {
            ans++;
            num++;
        }
        n = n>>1;
        int count = 1;
        while(n)
        {
            if(n & 1)
            {
                ans += num;
                num = num | (1 << count);
                ans+= count*(1<<(count - 1)) + 1;
            }
            n = n>>1;
            count++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends