//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define MOD 1000000007
class Solution{
public:

    int arr[1001][800];
    void solve(int n, int r)
    {
        //cout<<n<<' '<<r<<"bhau ";
        if(r > n) arr[n][r] = 0;
        else if(n == r || !r) arr[n][r] =  1;
        else if(n == r + 1 || r == 1) arr[n][r] = n;
        if(arr[n][r] == -1)
        {
            arr[n][r] = 0;
            if(arr[n - 1][r] == - 1) solve(n - 1, r);
            if(arr[n - 1][r - 1] == - 1) solve(n - 1, r - 1);
             arr[n][r] = (arr[n - 1][r]%MOD + arr[n - 1][r - 1]%MOD)%MOD;
        }
        //cout<<arr[n][r]<<"meow ";
    }
    
    int nCr(int n, int r){
        // code here
        memset(arr, -1, sizeof arr);
        
        for(int i = 1; i < 1001; i++)
        {
            if(i < 801)
            {
                arr[i][i] = 1;
                arr[i][i - 1] = i;
            }
            arr[i][0] = 1;
            arr[i][1] = i;
        }
        solve(n, r);
        return arr[n][r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends