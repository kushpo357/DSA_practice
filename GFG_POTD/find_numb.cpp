//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long n){
        // Code here
        long long ans = 0;
        long long p = 1;
        while(n)
        {
            int temp;
            if(n%5) temp = 2*(n % 5) - 1;
            else temp = 9;
            ans = ans + temp*p;
            n /= 5;
            if(temp == 9) n--;
            p *= 10;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends