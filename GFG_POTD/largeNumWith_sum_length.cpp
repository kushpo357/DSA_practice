//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int sum){
        // code here
        if((!sum && n > 1) || sum > n*9) return "-1";
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            if(sum >= 9)
            {
                ans.push_back('9');
                sum -= 9;
            }
            else if(sum > 0)
            {
                ans.push_back(sum + '0');
                sum = 0;
            }
            else ans.push_back('0');
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
