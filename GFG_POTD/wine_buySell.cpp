//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int n){
      //Code here.
      long long int buy = 0, sell = 0;
      long long int ans = 0;
      while(buy < n && sell < n)
      {
          while(arr[buy] <= 0)
          {
              buy++;
              if(buy == n) return ans;
          }
          while(arr[sell] >= 0)
          {
              sell++;
              if(sell == n) return ans;
          }
          
          if(abs(arr[buy]) > abs(arr[sell]))
          {
              ans += abs(arr[sell]) * abs(buy - sell);
              arr[buy] += arr[sell];
              arr[sell] = 0;
          }
          else
          {
              ans += arr[buy]*abs(buy - sell);
              arr[sell] += arr[buy];
              arr[buy] = 0;
          }
      }
      
      return ans;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends