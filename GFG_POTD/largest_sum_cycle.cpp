//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int sum = 0,cnt1 = 0;
    int dfs1(int node,vector<int>adj[],vector<int>&vis)
    {
        vis[node] = 1;
        for(auto &it : adj[node])
        {
            if(!vis[it])
                dfs1(it,adj,vis);
        }
        sum = sum + node;
        cnt1++;
    }
    
    int dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&st)
    {
        vis[node] = 1;
        for(auto &it : adj[node])
        {
            if(!vis[it])
                dfs(it,adj,vis,st);
        }
        st.push(node);
    }

 public:
  long long largestSumCycle(int N, vector<int> Edge)
  {
        vector<int>adj[N];
        
        for(int i = 0;i<N;i++)
        {
            int u = i;
            int v = Edge[i];
            if(v != -1)
                adj[u].push_back(v);
        }
        
        vector<int>vis(N+1,0);
        stack<int>st;
        
        for(int i=0;i<N;i++)
        {
            if(!vis[i])
                dfs(i,adj,vis,st);
        }

        vector<int>adj1[N];

        for(int i=0;i<N;i++)
        {
            vis[i] = 0;
            for(auto &it : adj[i])
            {
                adj1[it].push_back(i);
            }
        }
        
        int ans = 0,cnt = 0;
        while(st.size() != 0)
        {
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                sum = 0;
                cnt++;
                cnt1 = 0;
                dfs1(node,adj1,vis);
            }
            if(cnt1 > 1)
                ans = max(ans,sum);
        }
        
        if(cnt == N)
            return -1;
            
        return ans;
    }
};

//{ Driver Code Starts.
signed main(){
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
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends