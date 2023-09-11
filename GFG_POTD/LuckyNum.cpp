//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
public:
    bool isLucky(int n) {
        // code here
         vector<bool> v(n + 1, 1);
        
        for(int i = 2; (i - 2)*(i-2) <= n; i++)
        {
            int count = 0;
            for(int j = 1; j <= n; j++)
            {
                if(v[j])
                {
                    count++;
                    if(!(count % i))
                    {
                        v[j] = 0;
                        count = 0;
                    }
                }
            }
            if(!v[n]) return 0;
        }
        
        return v[n];
       
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends
