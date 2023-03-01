//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int n,int q,vector<vector<int>> &u)
        {
            // code here
            vector<vector<int>> bit(32,vector<int>(n+1,0));
            for(int i=0;i<q;i++){
                int l=u[i][0],r=u[i][1],x=u[i][2];
                l--;r--;
                for(int j=0;j<32;j++){
                    if(x&(1<<j)){
                        bit[j][l]++;
                        bit[j][r+1]--;
                    }
                }
            }
            for(int j=0;j<32;j++){
                for(int i=1;i<n;i++){
                    bit[j][i]+=bit[j][i-1];
                }
            }
            
            vector<int> fans(n);
            for(int j=0;j<32;j++){
                for(int i=0;i<n;i++){
                    if(bit[j][i]!=0){
                        fans[i]|=(1<<j);        
                    }
                }
            }
            
            return fans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends