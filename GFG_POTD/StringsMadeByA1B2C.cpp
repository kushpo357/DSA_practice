//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


long long int countStr(long long int n){
    //complete the function here
    
    if(n == 1) return 3;
    if(n == 2) return 8;
    
    long long ans = 1;
    ans += 2*n;
    ans += n*(n - 1)*(n + 1)/2;
    
    return ans;
}
