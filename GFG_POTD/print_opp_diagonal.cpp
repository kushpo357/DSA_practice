//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> a)
	{
		// Your code goes here
		vector<int> v;
		int i = 0, j = 0;
		while(i < n  && j < n)
		{
		    v.push_back(a[i][j]);
		    if(i == n - 1)
		    {
		        i = j + 1;
		        j = n - 1;
		    }
		    else if(j == 0)
		    {
		        j = i + 1;
		        i = 0;
		    }
		    else
		    {
		        i++;
		        j--;
		    }
		}
		return v;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends