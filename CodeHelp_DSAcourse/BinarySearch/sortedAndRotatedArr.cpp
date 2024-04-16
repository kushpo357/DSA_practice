int binsearch(vector<int>& arr, int s, int e, int k)
{
    while(s <= e)
    {
        int mid = s + (e - s)/2;
        if(arr[mid] == k) return mid;
        else if(arr[mid] > k) e = mid - 1;
        else s = mid + 1;
    }

    return -1;
}
int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int l = 0, r = n - 1, p;
    while(l < r)
    {
        p = l + (r - l)/2;
        if(arr[p] > arr[p + 1]) break;
        else if(arr[p] >= arr[r]) l = p;
        else r = p;
    }

    if(l == r) return binsearch(arr, 0, n - 1, k);
    if(arr[0] <= k) return binsearch(arr, 0, p, k);
    return binsearch(arr, p + 1, n - 1, k);
}
