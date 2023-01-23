//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<char>sp;
        
        for(int i=0;i<s.size();i++)
        {
            
            if(!(sp.empty()) and sp.top()==s[i] )
                sp.pop();
            else 
                sp.push(s[i]);
            
        }
        
        string ans="";
        
        while(!sp.empty())
        {
            ans+=sp.top();
            sp.pop();
        }
        
        if(ans.size()==0)
            return to_string(-1);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends