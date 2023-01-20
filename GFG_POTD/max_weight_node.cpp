//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> edge)
  {
      // code here
      map<int, int> mp;
      
      for(int i = 0; i < n; i++)
            mp[edge[i]] += i;
      
      int maxi = INT_MIN;
      int ans;
      
      for(auto i : mp)
      {
          if(i.second > maxi)
          {
              maxi = i.second;
              ans = i.first;
          }
          else if(i.second == maxi)
              ans = max(ans, i.first);
              
      }
      
      if(ans == -1)
        return 0;
      else
        return ans;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends