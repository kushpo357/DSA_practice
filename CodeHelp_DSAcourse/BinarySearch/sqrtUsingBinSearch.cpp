int floorSqrt(int n)
{
    // Write your code here.
    long long l = 1, r = n, mid;
    while(l <= r)
    {
        mid = l + (r - l)/2;
        if(mid*mid == n) return (int)mid;
        else if(mid*mid > n) r = mid - 1;
        else l = mid + 1;
    }
    while(mid*mid > n) mid--;

    return (int)mid;
}
