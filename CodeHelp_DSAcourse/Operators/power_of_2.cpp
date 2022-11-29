class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        int one = 0;
        
        if(n <= 0)
            return false;
        
        if(!(n & (n - 1)))
            return true;
        else
            return false;
        
    }
};