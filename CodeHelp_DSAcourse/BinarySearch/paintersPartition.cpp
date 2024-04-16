bool ispossible(vector<int> &arr, int n, int k, int mid)
{
    int workersnum = 1;
    int curr = 0;
    for(int i = 0; i < n; i++)
    {
        curr += arr[i];
        //cout<<curr<<endl;
        if(workersnum > k || arr[i] > mid) return 0;
        if(curr > mid)
        {
            curr = 0;
            i--;
            workersnum++;
            //cout<<"bhau bhau "<<workersnum<<endl;
        }
    }

    return 1;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.

    int s = 0, ans = 0, e = 0, mid = 0;
    int n = boards.size();

    for(int i = 0; i < n; i++) e += boards[i];

    while(s <= e)
    {
        mid = s + (e - s)/2;

        if(ispossible(boards, n, k, mid))
        {
            //cout<<"bhau"<<endl;
            ans = mid;
            e = mid - 1;
        }
        else s = mid + 1;
    }

    return ans;
}