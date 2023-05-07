//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        int i = 0, n = str.size();
        for(i = 1; i < n; i++) 
        {
            if(str[i] > str[i - 1]) break;
            else if(str[i - 1] == str[i] && i == 1) break;
        }
        
        string ans = "";
        
        for(int j = 0; j < i; j++) ans.push_back(str[j]);
        while(i-- > 0) ans.push_back(str[i]);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends