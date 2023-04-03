//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
       // code here
       int num = x[0] - 48;
       int n = x.size();
       int i = 0;
       
       while(i < n - 1)
       {
           if(!(num / 11))
           {
               i++;
               num = num * 10 + x[i] - 48;
           }
           else num %= 11;
       }
       num %= 11;
        
        return num;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends