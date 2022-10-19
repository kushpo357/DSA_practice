//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<vector<int>> V;
    bool dfs(int v,int label[15],int count,int N)
    {
    	label[v]=1;
    	if(count==N)
    	return true;
    	
    	for(int j=0;j<V[v].size();j++)
    	{
    		if(label[V[v][j]]==0)
    		{
    			if(dfs(V[v][j],label,count+1,N))
    			return true;
    			label[V[v][j]]=0;
    		}
    	}
    	return false;
    }
 
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        V=vector<vector<int>>(N+1);
        
        for(auto i:Edges)
        {
            V[i[0]].push_back(i[1]);
		    V[i[1]].push_back(i[0]);
        }
        
    	int label[15];
    	
    	for(int i=0;i<=N;i++)
    		label[i]=0;
    	
    	for(int i=1;i<=N;i++)
    	{
    		if(dfs(i,label,1,N))
    		return true;
    		label[i]=0;
    	}
    	return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends