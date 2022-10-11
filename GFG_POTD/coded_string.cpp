//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        string curr = "", prev;
        int currno = 0, prevno;
        stack<string> stackstr;
        stack<int> stackint;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(isdigit(s[i]))
                currno = currno*10 + (s[i] - '0');
            else if(isalpha(s[i]))
                curr.push_back(s[i]);
            else if(s[i] == '[')
            {
                stackstr.push(curr);
                stackint.push(currno);
                currno = 0;
                curr = "";
            }
            else if(s[i] == ']')
            {
                prev = stackstr.top();
                stackstr.pop();
                prevno = stackint.top();
                stackint.pop();
                
                for(int j = 0; j < prevno ; j++)
                    prev = prev + curr;
                
                curr = prev;
            }
        }
        return curr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends