//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        //code here
        
        int t = max(m, n);
        vector<int> curr(t + 1, 0), prev(t + 1, 0);
        
        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(x[i] == y[j])
                curr[j] = 1 + prev[j + 1];
                else
                {
                    curr[j] = max(curr[j + 1], prev[j]);
                }
                
            }
            
            prev = curr;
        }
        
        return m + n - prev[0];
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends
