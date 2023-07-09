//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        int one = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
              one = 1;
              break;
            }
        }
        
        if (one == 0) return 1;
        
        for (int i = 0; i < n; i++)
            if (arr[i] <= 0 || arr[i] > n) arr[i] = 1;
            
        for (int i = 0; i < n; i++) arr[(arr[i] - 1) % n] += n;
        
        for (int i = 0; i < n; i++)
            if (arr[i] <= n) return i + 1;
          
        return n + 1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends