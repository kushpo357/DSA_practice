//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int n, vector<int> p){
        // code here
        
        vector<int> v(n, 0);
        
        for(int i = 1; i < n; i++)
        {
            v[p[i]]++;
            v[i]++;
        }
        
        int ans = n - 1;
        for(int i = 0; i < n; i++)
            if(v[i] == 1) ans--;
        
        if(ans < 0) return 0;
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends