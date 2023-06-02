//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
private:
    vector<int> primes;
    int N;
public:
    void precompute(){
        int max_size = 500000;
        vector<int> isPrime(max_size+1, true);
        for(int p = 2; p*p < max_size; p++){
            if(isPrime[p]){
                for(int i = p*p; i < max_size; i+=p){
                    isPrime[i] = false;
                }
            }
        }
        for(int p = 2; p < max_size; p++){
            if(isPrime[p]){
                primes.push_back(p);
            }
        }
    }
    
    int bfs(int node,vector<vector<int>> &graph, vector<int> &vis){
        int count = 0;
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int q_size = q.size();
            while(q_size--){
                int curr_node = q.front();
                q.pop();
                count++;
                for(int child : graph[curr_node]){
                    if(!vis[child]){
                        vis[child] = 1;
                        q.push(child);
                    }
                }
            }
        }
        return count;
        
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        if(m == 0){
            return -1;
        }
        vector<int> vis(n+1, 0);
        N = n;
        int max_size = 0;
        for(int node = 1; node <= N; node++){
            if(!vis[node]){
                max_size = max(max_size, bfs(node, g, vis));
            }
        }
        return primes[max_size-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends