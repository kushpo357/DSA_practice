//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        // code here
        long long int x = 0, y = 0, z = 0, temp = 1;
        
        for(long long int i = 0; i < n; i++)
            x ^= arr[i];
        
        while(!(x%2))
        {
            temp*=2;
            x/=2;
        }
        
        for(long long int i = 0; i < n; i++)
        {
            if(arr[i] & temp)
                y ^= arr[i];
            else
                z ^= arr[i];
        }
        
        vector<long long int> v = {max(y,z),min(y,z)};
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends