//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
  vector<int> maximumToys(int n, vector<int> a, int q, vector<vector<int>> que){
      // code here
      vector<pair<int, int>> arr(n);
      
      for(int i = 0; i < n ; i++) arr[i] = {a[i], i};
      
      sort(arr.begin(), arr.end());
      
      map<int, int> mp;
      
      for(int i = 0; i < n; i++) mp[arr[i].second] = i;
      
      vector<long long> prefix(n + 1);
      
      prefix[0] = 0;
      
      for(int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + arr[i - 1].first;
      
      
      vector<int> res(q);
      for(int i = 0; i < q; i++)
      {
          long long c = que[i][0];
          int k = que[i][1];
          int l = 0;
          int r = n;
          int ans = 0;
          while(l <= r)
          {
              int mid = l + (r - l)/2;
              
              if(prefix[mid] <= c)
              {
                  ans = mid;
                  l = mid + 1;
              }
              
              else r = mid - 1;
              
          }
          
          if(ans <= 0)
          {
              res[i] = 0;
              continue;
          }
          
          int idx = ans - 1;
          
          long long rem = c - prefix[ans];
          
          set<int> notRemoved;
          
          for(int j = 0; j < k; j++)
          {
              int qidx = mp[que[i][j + 2] - 1];
              
              if(qidx <= idx)
              {
                  ans--;
                  rem += arr[qidx].first;
              }
              else
                notRemoved.insert(qidx);
          }
          
          int s = idx + 1;
          while(s < n && arr[s].first <= rem)
          {
              if(!notRemoved.count(s))
              {
                  ans++;
                  rem -= arr[s].first;
              }
              s++;
          }
          
          res[i] = ans;
      }
      
      return res;
  }
};

//{ Driver Code Starts.
int main() {
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    int N;
    cin>>N;
    vector<int>A(N);
    for(auto &i:A){
      cin>>i;
    }
    int Q;
    cin>>Q;
    vector<vector<int>> Queries(Q);
    for(int i=0;i<Q;i++){
      int x,y;
      cin>>x>>y;
      Queries[i].push_back(x);
      Queries[i].push_back(y);
      for(int j=0;j<Queries[i][1];j++){
        cin>>x;
        Queries[i].push_back(x);
      }
    }
    Solution obj;
    auto ans =obj.maximumToys(N,A,Q,Queries);
    for(auto i:ans)
      cout<<i<<" ";
    cout<<endl;
 }
}
// } Driver Code Ends