//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    
    const long long int MOD = 1000000007;
    long long int numoffbt(long long int arr[], int n){
        // Your code goes here
        long long int ans = 0, maxi = INT_MIN, mini = INT_MAX;
        
        for(int i = 0; i < n; i++)
        {
            maxi = max(maxi, arr[i]);
            mini = min(mini, arr[i]);
        }
        
        vector<bool> pres(maxi + 1, false);
        vector<long long int> solve(maxi + 1, 0);
        
        for(int i = 0; i < n; i++)
        {
            pres[arr[i]] = true;
            solve[arr[i]] = 1;
        }
        
        for(int i = mini; i <= maxi; i++)
        {
            if(!pres[i])
                continue;
                
            for(int j = 2; i*j <= maxi && j <= i; j++)
            {
                int pd = i*j;
                
                if(!pres[pd])
                    continue;
                    
                solve[pd] = (solve[pd] + (solve[i]*solve[j])%MOD)%MOD;
                
                if(i != j)
                    solve[pd] = (solve[pd] + (solve[i]*solve[j])%MOD)%MOD;
            }
            
            ans = (ans + solve[i])%MOD;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<<ob.numoffbt(a,n)<<endl;
		
	}
	return 0;
}


// } Driver Code Ends