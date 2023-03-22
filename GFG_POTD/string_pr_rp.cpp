//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int x, int y, string s){
      //code here
      
      long long ans=0;
      
      if(x > y)
      {
          long long p = 0, r = 0;
          for(int i = 0; i < s.length(); i++)
          {
              if(s[i] == 'p') p++;
              else if(s[i] == 'r')
              {
                  if(p!=0)
                  { 
                    ans+=x;
                    p--;
                  }
                  else r++;
              }
              else
              {
                  long long a;
                  if(p < r) a = p;
                  else a = r;
                  ans += a * (y);
                  p = 0;
                  r = 0;
                  
              }
          }
          long long a;
                  if(p < r) a = p;
                  else a = r;
                  ans += a*(y);
      }
      else
      {
          long long p = 0, r = 0;
          for(int i = 0; i < s.length(); i++)
          {
              if(s[i] == 'r')
                  r++;
              else if(s[i] == 'p')
              {
                  if(r != 0)
                 { 
                    ans += y;
                    r--;
                 }
                  else p++;
              }
              else
              {
                  long long a;
                  if(p < r) a = p;
                  else a = r;
                  ans += a*(x);
                  p = 0;
                  r = 0;
              }
          }
          long long a;
          if(p < r) a = p;
          else a = r;
          ans += a*(x);
      }
      
      return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends