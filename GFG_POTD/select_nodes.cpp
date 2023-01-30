//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int count=0;
  bool dfs(vector<int> adj[],vector<int> &visited,int node){
      //mkae node visted
      visited[node]=1;
      bool select=false;
      for(auto i:adj[node]){
          if(visited[i]==0){
              
            //call the dfs for the child
            bool isChildSelected=dfs(adj,visited,i);
            
            //means if child is not selected than select the parent
            if(!isChildSelected){
                select=true;
            }
          }
          
      }
      
      //increment the count if the current node is selected
      if(select){
          count++;
      }
      return select;
      
  }
  
    int countVertex(int N, vector<vector<int>>edges){
        
        //making adjacency matrix
        vector<int> adj[N+1];
        for(auto i:edges){
            int v=i[0];
            int u=i[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        
        //visted array
        vector<int> visited(N+1,0);
        dfs(adj,visited,1);
        return count;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends