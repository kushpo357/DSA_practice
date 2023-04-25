//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    #define MOD 1000000007
    vector<int> mp;
    Solution()
    {
        mp.resize(31);
        vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for(int i = 2; i <= 30; ++i)
        {   if(!(i % 4) || !(i % 9) || !(i % 25)) continue;
            int mask = 0;
            for(int j = 0; j < 10; j++)
                if(0 == i % prime[j]) mask |= 1 << j;
            mp[i] = mask;
        }
    }
    long pow(int n)
    {
        long ans = 1, m = 2;
        while(n != 0)
        {
            if(1 == (n & 1)) ans = (ans * m) % MOD;
            m = m * m %MOD;
            n >>= 1;
        }
        return ans;
    }
    int goodSubsets(vector<int> &arr, int n){
        // Code here
        int count1 = 0;
        vector<int> dp(1024), cnt(31);
        dp[0] = 1;
        for(int i : arr)
        {
            if(i == 1) count1++;
            else if(mp[i] != 0) cnt[i]++;
        }
        
        for(int i = 0; i < 31; i++)
        {
            if(cnt[i] == 0) continue;
            for(int j = 0; j < 1024; j++)
            {
                if(0 != (j & mp[i]) ) continue;
                dp[j | mp[i]] = (int) ((dp[j | mp[i]] + dp[j] * (long) cnt[i]) % MOD);
            }
        }
        long ans=0; 
        for(int i : dp) ans = (ans + i) % MOD;
        ans--;
        if(count1 != 0) ans = ans * pow(count1) % MOD;
        return (int)ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        cout<<ob.goodSubsets(a, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends