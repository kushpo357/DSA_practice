//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int arr[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int count = 0;
 		int rowstart = 0, rowend = m - 1;
 		int colstart = 0, colend = n - 1;
 		int i = 0, j = 0;
 		while(count < k)
 		{
 		    for(j = rowstart; j <= rowend && count < k; j++, count++);
 		    j--;
 		    if(count == k)
 		    {
 		        return arr[i][j];
 		    }
 		    colstart++;
 		    for(i = colstart; i <= colend && count < k; i++, count++);
 		    i--;
 		    if(count == k)
 		    {
 		        return arr[i][j];
 		    }
 		    rowend--;
 		    for(j = rowend; j >= rowstart && count < k; j--, count++);
 		    j++;
 		    if(count == k)
 		    {
 		        return arr[i][j];
 		    }
 		    colend--;
 		    for(i = colend; i >= colstart && count < k; i--, count++);
 		    i++;
 		    if(count == k)
 		    {
 		        return arr[i][j];
 		    }
 		    rowstart++;
 		}
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends