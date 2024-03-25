//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    
private:
    
    int n;
    
public:	

    void solve(vector<string> &ans, string &s, int ones, int currsize)
    {
        if(currsize == n)
        {
            ans.push_back(s);
            return;
        }
        if(ones*2 >= currsize) 
        {
            s.push_back('1');
            solve(ans, s, ones + 1, currsize + 1);
            s.pop_back();
        }
        if(ones*2 > currsize)
        {
            s.push_back('0');
            solve(ans, s, ones, currsize + 1);
            s.pop_back();
        }
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    
	    this->n = n;
	    int ones = 0;
	    vector<string> ans;
	    string s = "";
	    solve(ans, s, ones, 0);
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends
