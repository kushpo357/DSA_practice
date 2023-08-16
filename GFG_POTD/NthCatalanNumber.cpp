//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        vector<int> v(1001, 0);
        v[0] = v[1] = 1;
        
        for(int i = 2; i <= n; i++)
        {
            for(int j = 0; j < i; j++)
                v[i] = (v[i] %1000000007 + (1ll*v[j]*v[i - j - 1] % 1000000007)) % 1000000007;
        }
        return v[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends
