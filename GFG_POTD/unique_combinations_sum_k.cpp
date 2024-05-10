//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    void solve(vector<int> &arr, int n, int k, int ind, int sum, vector<int> &curr, vector<vector<int>> &ans)
    {
        if(k < sum) return;
        
        if(sum == k)
        {
            ans.push_back(curr);
            return;
        }
        
        for(int i = ind; i < n; i++) {
            if(i > ind && arr[i] == arr[i - 1])
                continue;
            
            curr.push_back(arr[i]);
            solve(arr, n, k, i + 1, sum + arr[i], curr, ans);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        
        vector<vector<int>> ans;
        vector<int> curr;
        sort(arr.begin(), arr.end());
        solve(arr, n, k, 0, 0, curr, ans);
        
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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
