//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        // code here
        int ans = 0;
        int n = s.size();
        
        for(int i = 0; i < n; i++)
        {
            int lower = 0;
            int upper = 0;
            for(int j = i; j < n; j++)
            {
                if(islower(s[j])) lower++;
                else upper++;
                
                if(lower == upper) ans++;
            }
        }
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
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends