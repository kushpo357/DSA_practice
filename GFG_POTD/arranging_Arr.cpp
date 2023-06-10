//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        bool static comp(int a, int b)
        {
            if(a < 0 && b < 0)
            {
                if(a > b) return 1;
                return 0;
            }
            if(a < b) return 1;
            return 0;
        }
        void Rearrange(int arr[], int n)
        {
            // Your code goes here
            int negsum = 0, possum = 0;
            for(int i = 0 ; i < n; i++)
            {
                if(arr[i] < 0) negsum = arr[i] += negsum;
                else possum = arr[i] += possum;
            }
            sort(arr, arr + n, comp);
            int temp = arr[0];
            for(int i = 1; i < n; i++)
            {
                if(temp < 0 && arr[i] >= 0)
                {
                    temp = arr[i];
                    continue;
                }
                arr[i] -= temp;
                temp += arr[i];
            }
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends