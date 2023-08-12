//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> v;
       v.push_back(a[0]);
       for(int i = 1; i < n; i++)
       {
           vector<int>::iterator it = upper_bound(v.begin(), v.end(), a[i]);
           if(*(it - 1) == a[i]) continue;
           if(it == v.end()) v.push_back(a[i]);
           else *it = a[i];
       }
       
       //for(auto i : v) cout<<i<<endl;
       return v.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends