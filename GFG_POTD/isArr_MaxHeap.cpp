//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        
        for(int i = 0, j = 1, count = 0; j < n; j++)
        {
            if(count == 2)
            {
                i++;
                count = 0;
            }
            if(arr[i] < arr[j]) return 0;
            count++;
            //cout<<i<<' '<<j<<endl;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends
