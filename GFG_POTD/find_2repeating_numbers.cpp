//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        // Your code here
        
        int ansmask = 0;
        
        for(int i = 1; i <= n; i++) ansmask ^= i;
        
        for(int i = 0; i < n + 2; i++) ansmask = ansmask ^ arr[i];
        
        int msb = 1;
        ansmask = ansmask >> 1;
        while(ansmask)
        {
            msb = msb << 1;
            ansmask = ansmask >> 1;
        }
        
        int big = 0, small = 0;
        
        for(int i = 1; i <= n; i++)
        {
            if(i & msb) big = big ^ i;
            else small = small ^ i;
        }
        
        for(int i = 0; i < n + 2; i++)
        {
            if(arr[i] & msb) big = big ^ arr[i];
            else small = small ^ arr[i];
        }
        
        int bigoccur = 0, smalloccur = 0;
        for(int i = 0; i < n + 2; i++)
        {
            if(small == arr[i])
            {
                smalloccur++;
                if(smalloccur == 2)
                return {small, big};
            }
            if(big == arr[i])
            {
                bigoccur++;
                if(bigoccur == 2)
                return {big, small};
            }
        }
        
        return {big, small};
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}

// } Driver Code Ends
