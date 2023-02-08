//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      vector<long long int>v;
      long long int tot = n*n;
      unordered_map<int,int>row;
      unordered_map<int,int>col;
      
    for(int i = 0; i < k; ++i)
    {
        long long int tmp = tot;
        int r = arr[i][0];
        int c = arr[i][1];
        
        row[r] = 1;
        col[c] = 1;
        int r_sz = row.size();
        int c_sz = col.size();
        
        tmp = tmp - c_sz*n;
        tmp = tmp - (n-c_sz)*r_sz;
        v.push_back(tmp);
    }
      return v;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends