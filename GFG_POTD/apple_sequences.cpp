//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        
        int a = 0, o = 0, mx = INT_MIN;
        int s = -1, e = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[e++] == 'A') a++;
            else o++;
            if(o > m)
            {
                mx = max(mx, a + o - 1);
                while(o > m)
                {
                    ++s;
                    
                    if(arr[s] == 'A') a--;
                    else o--;
                }
            }
        }
        
        mx = max(mx, min(a + m, n));
        
        return mx;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends