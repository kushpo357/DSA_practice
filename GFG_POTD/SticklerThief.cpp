//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n == 1) return arr[0];
        if(n == 2) return max(arr[0], arr[1]);
        int a = arr[n - 1], b = arr[n - 2], c = arr[n - 3] + arr[n - 1];
        for(int i = n - 4; i >= 0; i--)
        {
            int temp = arr[i] + max(a, b);
            a = b;
            b = c;
            c = temp;
        }
        return max(b, c);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends
