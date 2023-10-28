//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	    // Code here.
	    
	    int temp = n;
	    int maxsetbit = 0;
	    while(temp)
	    {
	        temp = temp>>1;
	        maxsetbit++;
	    }
	    
	    for(int i = 1; i <= maxsetbit; i++)
	    {
	        temp = n - i;
	        int setbits = 0;
	        while(temp)
	        {
	            if(temp & 1)
	                setbits++;
	            temp = temp>>1;
	        }
	        if(setbits == i) return 0;
	    }
	    
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code End
