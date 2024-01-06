//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    
	    vector<bool> sieve(b + 1, 1);
	    
	    for(int i = 2; i*i <= b; i++)
	    {
	        if(sieve[i])
	        {
	            for(int j = i*i; j <= b; j += i)
	                sieve[j] = false;
	        }
	    }
	    
	    int suma = 0, sumb = 0;
	    
	    for(int i = 2; i <= b; i++)
	    {
	        if(sieve[i])
	        {
	            int temp = i;
	            while(temp <= b)
	            {
	                if(temp < a) suma += (a - 1)/temp;
	                sumb += b/temp;
	                //cout<<i<<' '<<temp<<' '<<(a - 1)/temp<<' '<<b/temp<<endl;
	                temp *= i;
	            }
	        }
	    }
	    
	    return sumb - suma;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
