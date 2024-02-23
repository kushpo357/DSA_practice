//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
        
        int maxSum(int n)
        {
            //code here.
            
            vector<int> val(n + 1, 0);
            for(int i = 0; i <= n; i++)
            {
                val[i] = max(i, val[i/2] + val[i/3] + val[i/4]);
            }
            
            return val[n];
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
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
