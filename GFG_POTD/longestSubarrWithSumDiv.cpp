//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k)
    {
        // Complete the function
        unordered_map<int,int> m;
        
        int maxi=0;
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            int x=sum%k;
            
            if(x==0){
                maxi=max(maxi,i+1);
            }
            if(x<0){
                x+=k;
            }
            if(m.find(x)==m.end()){
                
               
                m[x]=i;}
            else{
                
                
              
                maxi=max(maxi,i-m[x]);
            }
            
            
           //cout<<sum<<endl; 
        }
        
        
       
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends
