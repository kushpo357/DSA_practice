#include <bits/stdc++.h> 
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here

    int minind = -1, maxind = -1;
    int l = 0, r = n - 1, mid;
    bool found = 0;
    while (l <= r) 
    {
        mid = l + (r - l)/2;
        if(arr[mid] == k) minind = mid;
        if(arr[mid] < k) l = mid + 1;
        else r = mid - 1;
    }

    l = 0;
    r = n - 1;

    while (l <= r) 
    {
        mid = l + (r - l)/2;
        if (arr[mid] == k) maxind = mid;
        if(arr[mid] <= k) l = mid + 1;
        else r = mid - 1;
    }

    return {minind, maxind};
}