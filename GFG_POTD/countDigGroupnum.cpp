//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    
public:

    int solve(string &str, int start, int prevSum, const int &n, vector<vector<int>> &dp)
    {
        if(start == n) return 1;
        int sum = 0;
        int ans = 0;
        for(int i = start; i < n; ++i)
        {
            sum += str[i] - '0';
            if(sum >= prevSum)
            {
                if(dp[start][i] == -1) dp[start][i] = solve(str, i + 1, sum, n, dp);
                ans += dp[start][i];
            }
        }
        return ans;
    }
    int TotalCount(string str){
        // Code here
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(str, 0, 0, n, dp);
    }
 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
