//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    set<vector<int>>st ;
    
    void solve( vector<int>&arr , int index )
    {
        if( index == arr.size() )
        {
            st.insert(arr) ;
            return ;
        }
        
        for( int i = index ; i < arr.size() ; i++ )
        {
            swap( arr[i] , arr[index] ) ;
            solve( arr , index+1 )  ;
            swap( arr[i] , arr[index] ) ;
        }
        
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        st.clear() ;
        solve( arr , 0 ) ;
        vector<vector<int>>ans( st.begin() , st.end() ) ;
        return ans ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
