class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
         
        int n = arr.size();
        int l = 0, r = n - 1;
        int mid;
        while(l <= r)
        {
            mid = l + (r - l)/2;
            if(mid == 0) mid++;
            if(mid == n - 1) mid--;
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) break;
            else if(arr[mid] > arr[mid - 1] && arr[mid + 1] > arr[mid]) l = mid + 1;
            else r = mid - 1;
        }

        return mid;
    }
};