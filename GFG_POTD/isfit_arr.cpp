//{ Driver Code Starts
/* Driver program to test above function */
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution{
public:
    
    bool isFit(int arr[], int brr[], int n){
        // code here
        bool check = true;
        
        heapSort(arr, n);
        
        heapSort(brr, n);
        
        for(int i = 0; i < n; i++){
            
            if (arr[i] > brr[i]){
                check = false;
                break;
            }
        }
        
        return check;
    }
    
    void swap (int *a, int *b){
        
        int temp;
        
        temp = *a;
        
        *a = *b;
        
        *b = temp;
        
    }
    
    void heapify( int arr[], int n, int i){
    
        int largest = i;
        
        int left = 2 * i + 1;
        
        int right = 2 * i + 2;
        
        if (left < n && arr[left] > arr[largest])
            
            largest = left;
            
        if (right < n && arr[right] > arr[largest])
            
            largest = right;
        
        if (largest != i){
            
            swap(&arr[i], &arr[largest]);
            
            heapify(arr, n, largest);
        }
    }
    
    void heapSort(int arr[], int n){
        
        for (int i = n / 2 - 1; i >= 0; i--)
        
            heapify(arr, n, i);
            
        for(int i = n - 1; i >= 0; i--){
        
            swap(&arr[0], &arr[i]);
            
            heapify(arr, i, 0);
            
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int i,j,z,t,n,flag;
    cin>>t;
    for(z=0;z<t;z++)
    {
        flag=0;
        cin>>n;
        int arr[n+1], brr[n+1];
        
        for(i=0;i<n;i++)
            cin>>arr[i];
        for(i=0;i<n;i++)
            cin>>brr[i];
        
        Solution ob;
        
        if(ob.isFit(arr, brr, n))  cout<<"YES\n";
        else
            cout << "NO\n";
            
        
    }
    return 0;
}
// } Driver Code Ends