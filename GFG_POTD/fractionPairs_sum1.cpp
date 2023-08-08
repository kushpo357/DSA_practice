//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int num[], int denom[])
    {
        for(int i = 0; i < n; i++)
        {
            int temp = __gcd(num[i], denom[i]);
            num[i] /= temp;
            denom[i] /= temp;
        }
        
        map<int, map<int, int>> mp;
        
        int ans = 0;
        int onebytwo = 0;
        for(int i = 0; i < n; i++)
        {
            if(denom[i] == 2)
            {
                onebytwo++;
                continue;
            }
            
            mp[denom[i]][num[i]]++;
        }
        
        for(auto &m : mp)
        {
            for(auto &i : m.second)
            {
                auto it = m.second.find(m.first - i.first);
                if(it != m.second.end())
                {
                    ans += (it->second)*i.second;
                    i.second = it->second = 0;
                }
            }
        }
        
        if(onebytwo == 1 || onebytwo == 0) onebytwo = 0;
        else
        {
            onebytwo = (onebytwo*(onebytwo - 1))/2;
        }
        
        ans += onebytwo;
        return ans;
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends