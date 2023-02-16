//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int trav(int n, vector<int> &arr, vector<int> &vis, int i)
    {  
        if(vis[i] == 0) return 0;
        
        if(vis[i] == 1) return 1;
        
        if(i + arr[i] < 0 || i + arr[i] >= n)
        {
            vis[i] = 1;
            return 1;
        }
        
        vis[i] = 0;
        vis[i] = trav(n, arr, vis, i + arr[i]);
        
        return vis[i];
    }
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int> vis(n, -1);
        
        for(int i = 0; i < n ; i++)
        {
            if(vis[i] == -1)
                vis[i] = trav(n, arr, vis, i);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
            if(vis[i]) ans++;
            
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
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends