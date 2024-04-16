class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k % n;
        if(!k) return;
        int count = 0;
        for(int i = 0; i < k && count < n; i++)
        {
            int j = i + k;
            int prev = nums[i];
            while(j % n != i)
            {
                swap(prev, nums[j % n]);
                j += k;
                count++;
            }
            swap(prev, nums[j % n]);
            count++;
        }
    }
};
//Check if the Array is Sorted and Rotated
