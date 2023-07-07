//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            long long int mx = 0, mn = INT_MAX;
            
            for(int i = 0; i < n; i++)
            { 
                mx = max(mx, arr1[i]);
                mn = min(mn, arr1[i]);
            }
            for(int i = 0; i < m; i++)
            {
                mx = max(mx, arr2[i]);
                mn = min(mn, arr2[i]);
            }
            int nthnum = 0;
            while(mx >= mn)
            {
                int lessnum = 0;
                long long int mid = (mx - mn)/ 2 + mn;
                
                for(int i = 0; i < n; i++)
                {
                    if(arr1[i] <= mid) lessnum++;
                    if(lessnum == n + 1)
                    {
                        nthnum = mid;
                        break;
                    }
                }
                if(lessnum == n + 1)
                {
                    mx = mn - 1;
                    continue;
                }
                for(int i = 0; i < m; i++)
                {
                    if(arr2[i] <= mid) lessnum++;
                    if(lessnum == n + 1)
                    {
                        nthnum = mid;
                        break;
                    }
                }
                if(lessnum == n + 1)
                {
                    mx = mid - 1;
                    continue;
                }
                else
                {
                    mn = mid + 1;
                }
            }
            bool swapped = 0;
            for(int i = 0; i < n && !swapped; i++)
            {
                if(arr1[i] == nthnum)
                {
                    swap(arr1[i], arr2[0]);
                    swapped = 1;
                } 
            }
            for(int i = 1; i < m && !swapped; i++)
            {
                if(arr2[i] == nthnum)
                {
                    swap(arr2[i], arr2[0]);
                    swapped = 1;
                }
            }
            sort(arr1, arr1 + n);
            sort(arr2 + 1, arr2 + m);
            int i = n - 1, j = 1;
            
            while(i < n && j < m && arr1[i] >= arr2[0] && arr2[j] <= arr2[0])
            {
                swap(arr1[i--], arr2[j++]);
            }
            
            sort(arr1, arr1 + n);
            sort(arr2 + 1, arr2 + m);
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends