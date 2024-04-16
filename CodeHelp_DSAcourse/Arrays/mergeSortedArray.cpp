class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if(!n) return;
        int i = m + n - 1, j = n - 1, k = m - 1;

        while(k < i && i >= 0)
        {
            if(k >= 0 && nums1[k] >= nums2[j])
            {
                nums1[i] = nums1[k];
                nums1[k] = 0;
                k--;
            }
            else nums1[i] = nums2[j--];

            i--;
        }
    }
};
//Merge the sorted array nums2 to sorted array nums1
