//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    int ispower(int a,int b, string st)
    {
        long long c = b - a, num = 0, f = 0;
        for(int i = a; i <= b; i++)
        {
            int dig = st[i] - '0';
            if(f == 0 && dig == 0) return 0;
            if(dig == 1) f = 1;
            num += dig * pow(2,c);
            c--;
        }
        
        if(num == 1) return 1;
        long long pw = 1;
        while(pw < num) pw = pw * 5;
        if(pw == num)   return 1;
        
        return 0;
    }
    
    int cuts(string s){
        int i , j, n = s.length(), dp[n];
        if(s[0] == '0') dp[0] = -1;
        else dp[0] = 1;
        for(i = 1; i < n; i++)
        {
            if(s[i] == '0') dp[i] = -1;
            else
            {
                dp[i] = -1;
                int ans = 1000;
                for(j = i ; j >= 0; j--)
                {
                    int p = ispower(j,i,s);
                    if(p == 1 && j > 0 && dp[j-1] != -1)
                    ans = min(ans, 1 + dp[j - 1]);
                    if(p == 1 && j == 0) ans = min(ans,1);
                }
                if(ans != 1000) dp[i] = ans;
            }
        }
        return dp[n-1]; 
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends