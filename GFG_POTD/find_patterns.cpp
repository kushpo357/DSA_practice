//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string s, string w){
        // code here
        int ans = 0, lens = s.size(), lenw = w.size();
        
        for(int i = 0; i < lens; i++)
        {
            if(s[i] == w[0])
            {
                for(int j = i, k = 0; j < lens; j++)
                {
                    if(s[j] == w[k])
                    {
                        k++;
                        s[j] = '0';
                    }
                    
                    if(k == lenw)
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends