//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
  
    bool prim(int n){

        for(int i=2;i<n;i++){

            if(n%i==0) {

            return 0;

            }

        }

        return 1;

    }

    int solve(int n){

        if(prim(n)){

            return n;

        }

        int s = 0;

        for(int i=2;i<n;i++){

            if(n%i==0 && prim(i)){

                s+=i;

            }

        }

        return s;
    }
        
    int sumOfAll(int l, int r){
        // code here
         int ans = 0;

        for(int i=l;i<=r;i++){

            ans+=solve(i);

        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin>>l>>r;
        Solution ob;
        cout<<ob.sumOfAll(l,r)<<endl;
    }
    return 0;
}

// } Driver Code Ends