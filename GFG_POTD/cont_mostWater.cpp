//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long a[], int len)
{
    // Your code goes here
    if(len == 1)
        return 0;
    int s = 0, e = len - 1;
    long long ans = (e - s)*min(a[s], a[e]);
    while(s < e)
    {
        if(a[s] <= a[e])
            s++;
        else e--;
        
        ans = max(ans, (e - s)*min(a[s], a[e]));
    }
    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends