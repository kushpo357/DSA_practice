//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        
        int l = 0, r = 0;
        long currans = 0, ans = 0;
        
        while(r < k)
        {
            currans += arr[r];
            r++;
        }
        
        ans = currans;
        //cout<<ans<<endl;
        while(r < n)
        {
            currans += arr[r];
            r++;
            currans -= arr[l];
            l++;
            
            ans = max(currans, ans);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
