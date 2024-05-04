//https://www.geeksforgeeks.org/problems/product-of-primes5328/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
#define MOD 1000000007

    vector<int> sieve(int n)
    {
        vector<bool> v(n + 1, 1);
        vector<int> prime;
        
        for(int i = 2; i*i <= n; i++)
        {
            if(v[i] == 0)
            continue;
            prime.push_back(i);
            for(int j = 2*i; j*j <= n; j +=i)
            {
                v[j] = 0;
            }
        }
        
        return prime;
    }
    long long primeProduct(long long l, long long r){
        // code here
        
        vector<int> prime = sieve(r);
        int n = prime.size();
        
        vector<bool> primelr(r - l + 1, 1);
        for(int i = 0; i < n; i++)
        {
            if(l % prime[i] == 0) primelr[0] = 0; 
            for(int j = (l/prime[i])*prime[i] + prime[i]; j <= r; j+= prime[i])
            {
                if(j == prime[i])
                    continue;
                primelr[j - l] = 0;
            }
        }
        
        int ans = 1;
        for(int i = 0; i < r - l + 1; i++)
        {
            if(primelr[i])
            {
                ans = (1ll*ans*(i + l)%MOD)%MOD;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
