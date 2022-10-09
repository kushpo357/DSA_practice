//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int NthTerm(int N){
		    // Code here
		    
		    if(N == 1)
		        return 1;
		        
		    int ans = 0, num, count = 0, prime = false;
		    num = N;
		    
		    for(int i = N ; i > 1 ; i--, ans++)
		    {
		        if(isPrime(i))
		        {
		            num = i;
		            break;
		        }
		    }
		    for(int i = N; i < N + ans; i++)
		    {
		        if(isPrime(i))
		        {
		            ans = i - N;
		            break;
		        }
		    }
		    
		    return ans;
		}
		bool isPrime(int num)
		{
		    bool prime = true;
		    
		    for(int i = 2; i <= sqrt(num); i++)
		    {
		        if(!(num % i))
		        {
		            prime = false;
		            break;
		        }
		    }
		    
		    return prime;
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
		int ans = obj.NthTerm(N);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends