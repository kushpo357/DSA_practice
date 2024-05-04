//https://leetcode.com/problems/count-primes/
class Solution {
public:
    int countPrimes(int n) {
        
        int ans = 0;
        vector<bool> sieve(n + 1, true);
        for(int i = 2; i*i <= n; i++)
        {
            if(!sieve[i])
                continue;
            for(int j = i * 2; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }

        for(int i = 2; i < n; i++)
        {
            if(sieve[i])
                ans++;
        }
        return ans;
    }
};
