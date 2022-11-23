class Solution {
public:
    int bitwiseComplement(int n) {
        
        int ans = 0, i = 0;
        if(!n)
            return 1;
        while(n)
        {
            if(!(n&1))
                ans = ans | (1 << i); 
            n = n>>1;
            i++;
        }
        return ans;
    }
};