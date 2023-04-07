//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        //code here
        int n = str.size();
        int i = 0, j = n - 1;
        int same = 0;
        
        while(i < j)
        {
            if(str[i] == str[j]) i++;
            else 
            {
                i = 0;
                if(str[0] == str[j]) i++;
            }
            
            j--;
        }
        
        return n - 1 - j - i;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends