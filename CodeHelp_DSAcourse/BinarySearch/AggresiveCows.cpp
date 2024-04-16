int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.

    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int s = 1, e = stalls[n - 1] - stalls[0], mid;
    int ans = 1;
    while(s <= e)
    {
        mid = s + (e - s)/2;
        int i, cownum = 2, currdis = stalls[1] - stalls[0], prev = stalls[0];
        for(i = 1; i < n && cownum <= k; i++)
        {
            currdis = stalls[i] - prev;
            if(currdis >= mid)
            {
                cownum++;
                prev = stalls[i];
            }
        }
        if(cownum < k || (i == n && cownum == k)) e = mid - 1;
        else
        {
            ans = mid;
            s = mid + 1;
        }
    }

    return ans;
}