//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    void update(int a[], int n, int updates[], int k)
    {
        // Your code goes here
        
        sort(updates, updates + k);
        int inc = 0;
        for(int i = 0, j = 0; i < n; i++)
        {
            if(j < k && i + 1 == updates[j])
            {
                j++;
                inc++;
                i--;
                continue;
            }
            a[i] += inc;
        }
    }
};

//{ Driver Code Starts.
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n]={0}, updates[k]={0};
		for(int i = 0; i < k; i++)
		cin>>updates[i];
		Solution ob;
		ob.update(a, n, updates, k);
		
		for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
		
		cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends