//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    #define MOD 1000000007
    long long countWays(int n)
    {
        
        // your code here
        if(n <= 2) return n;
        if(n == 3) return 4;
        long long a = 1, b = 2, c = 4;
        for(int i = 4; i <= n; i++)
        {
            long long temp;
            temp = (a % MOD + b % MOD + c % MOD) % MOD;
            a = b;
            b = c;
            c = temp;
        }
        return c;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends
