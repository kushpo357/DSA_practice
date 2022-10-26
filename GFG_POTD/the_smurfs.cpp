//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        map<char, int> m;
        m['R'] = 0;
        m['G'] = 0;
        m['B'] = 0;
        
        for(int i = 0; i < n; i++) m[a[i]]++;
        
        if((m['R'] & 1) && (m['G'] & 1) && (m['B'] & 1))
            return 2;
        
        if(!(m['R'] & 1) && !(m['G'] & 1) && !(m['B'] & 1))
            return 2;
            
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends