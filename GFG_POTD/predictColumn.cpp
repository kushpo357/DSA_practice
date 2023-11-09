//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    /*Function to count zeros in each column
    * N : Number of rows and columns in array
    M is the matrix that is globally declared
    */
    int columnWithMaxZeros(vector<vector<int>> arr,int n){
        
        // Your code here
        
        int maxcol = 0;
        int maxzero = 0;
        for(int i = 0; i < n; i++)
        {
            int currzero = 0;
            for(int j = 0; j < n; j++)
            {
                if(!arr[j][i])
                    currzero++;
            }
            
            if(maxzero < currzero)
            {
                maxzero = currzero;
                maxcol = i;
            }
        }
        
        if(maxzero == 0) return -1;
        return maxcol;
    }
};

//{ Driver Code Starts.
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    vector<vector<int>>arr(N,vector<int>(N));
	    // Taking elements input into the matrix
	    for(int i = 0;i<N;i++){
	        for(int j = 0;j<N;j++){
	            int x;
	            cin >> x; 
	            arr[i][j]=x;
	        }
	    }
	    Solution ob;
	    cout << ob.columnWithMaxZeros(arr,N) << endl;
	}
	
	return 0;
}
// } Driver Code Ends
