class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int ind = 0, i = 0;
        int n = nums.size();
        while(i < n && ind < n)
        {
            while(ind < n && !nums[ind]) ind++;
            if(ind >= n) break;
            if(ind != i) swap(nums[i], nums[ind]);
            i++;
            ind = i;
        }
    }
};
//move all the zeroes to the end while maintaining same order
