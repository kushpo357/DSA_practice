//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    pair<int,string> recur(int p[],int n,int low,int high, pair<int,string> dp[27][27])
    {
      if(low == high)
      {
          char ch='A' + low;
          string s="";
          s+=ch;
          return {0,s};
      }
      
      if(dp[low][high].first!=-1)
      {
          return dp[low][high];
      }
      
      pair<int,string> res;
      res.first=INT_MAX;
      
      for(int i=low;i<high;i++)
      {
          auto left=recur(p,n,low,i,dp);
          auto right=recur(p,n,i+1,high,dp);
          
          int tempRes=left.first+right.first+(p[low]*p[i+1]*p[high+1]);
          if(res.first>tempRes)
          {
              res.first=tempRes;
              res.second="("+left.second+right.second+")";
          }
      }
      
      return dp[low][high]=res;
      
  }
   string matrixChainOrder(int p[], int n){
       // code here
        
         pair<int,string> dp[27][27];
         pair<int,string> empty;empty.first=-1;
         
         for(int i = 0;i <= n; i++)
         {
             for(int j = 0; j <= n; j++)
             dp[i][j] = empty;
         }
         int low = 0,high = n - 2;
         
         return recur(p,n,low,high,dp).second;
   }
};

//{ Driver Code Starts.

int get(int p[],int n)
{
    int m[n][n],ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++){ 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                { 
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int find(string s,int p[])
{
    vector<pair<int,int>> arr;
    int ans = 0;
    for(auto t:s)
    {
        if(t=='(')
        {
            arr.push_back({-1,-1});
        }
        else if(t==')')
        {
            pair<int,int> b=arr.back();
            arr.pop_back();
            pair<int,int> a=arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first,b.second});
            ans += a.first*a.second*b.second;
        }
        else 
        {
            arr.push_back({p[int(t-'A')],p[int(t-'A')+1]});
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
        {
            cin>>p[i];
        }
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result,p)==get(p,n))
        {
            cout<<"True"<<endl;
        }
        else
        {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
