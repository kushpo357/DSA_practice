//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int a, int b, int c, int d){
        //code here
        int ta = a, tb = b;
        int ans1 = 0, ans2 = 0;
        
        while(ta > c) ta >>= 1, ans1++;
        while(tb > d) tb >>= 1, ans1++;
        
        ta = a; tb = b;
        
        while(ta > d) ta >>= 1, ans2++;
        while(tb > c) tb >>= 1, ans2++;
        
        return min(ans1, ans2);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends