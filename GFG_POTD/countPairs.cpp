//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	void increase(int &i, int &j, int n)
	{
	    if(j != n - 1)
	       j++;
	    else
	    {
	        j = 0;
	        i++;
	    }
	}
	
	void decrease(int &i , int &j, int n)
	{
	    if(j > 0)
	    {
	        j--;
	    }
	    else
	    {
	        j = n - 1;
	        i--;
	    }
	}
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    
	    int m1i = 0, m1j = 0;
	    int m2i = n - 1, m2j = n - 1;
	    
	    int ans = 0;
	    
	    while(m1i < n && m2i >= 0)
	    {
	        int currnum = mat1[m1i][m1j] + mat2[m2i][m2j];
	        if(currnum == x)
	        {
	            ans++;
	            increase(m1i, m1j, n);
	            decrease(m2i, m2j, n);
	        }
	        else if (currnum < x)
	        {
	            increase(m1i, m1j, n);
	        }
	        else
	        {
	            decrease(m2i, m2j, n);
	        }
	    }
	    
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
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends
