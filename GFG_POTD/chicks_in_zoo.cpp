//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    // Code here
	    long long int ans = 1, birth[n];
	    birth[0] = 1;
	    for(int i = 1; i < n; i++)
	    {
	        if(i >= 6)
	        {
	            //cout<<birth[i - 6]<<endl;
	            birth[i] = (ans - birth[i - 6])*2;
	            ans = (ans - birth[i - 6])*3;
	        }
	        else
	        {
	            birth[i] = ans*2;
	            ans *= 3;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends