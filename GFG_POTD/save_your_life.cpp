//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here 
          int len = w.size(), currsum = 0, maxsum = INT_MIN;
          int start = 0, end = 0, s= 0;
          for(int i = 0 ; i < len; i++)
          {
              currsum = currsum + w[i];
              for(int j = 0; j < n ; j++)
              {
                  if(w[i] == x[j])
                  {
                    currsum = currsum - w[i] + b[j];
                    break;
                  }
              }
              if(maxsum < currsum)
              {
                  maxsum = currsum;
                  start = s;
                  end = i;
              }
              if(currsum < 0)
              {
                  currsum = 0;
                  s = i + 1;
              }
          }
          
          if(end != len - 1)
                w.erase(w.begin() + end + 1, w.end());
          
          if(start != 0)
                w.erase(w.begin() , w.begin() + start);
            
          return w;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends