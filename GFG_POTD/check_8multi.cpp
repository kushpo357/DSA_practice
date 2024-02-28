//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        
        int n = s.size();
        int carry = 0;
        for(int i = 0; i < n; i++)
        {
            int num = s[i] - '0';
            carry = (num + carry*10) % 8;
            //cout<<carry<<endl;
        }
        
        if(carry) return -1;
        
        return 1;
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
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends
