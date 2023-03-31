//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            bool isodd = a[0] & 1;
            int num = -1;
            
            for(int i = 0; i < n; i++)
            {
                if((a[i] & 1) != isodd)
                {
                    isodd = a[i] & 1;
                    sort(a.begin() + i - num - 1, a.begin() + i, greater<int>());
                    num = 0;
                }
                else num++;
                //cout<<isodd<<' '<<num<<endl;
            }
            
            if(num)
                sort(a.end() - num - 1, a.end(), greater<int>());
            return a;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends