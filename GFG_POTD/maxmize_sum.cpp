//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)//get the frequency of every element
            mp[a[i]]++;
        
        int ans = 0;
        for(int i=n-1;i>=0;i--) // now traverse the elements from back as said in the question
        {
            if(mp[a[i]]>0) // if it's freq is greater than 0 
            {
                ans+=a[i]; // add this to the answer
                mp[a[i]]--;//reduce freq of this(a[i]) element 
                if(mp.find(a[i]-1)!=mp.end())
                mp[a[i]-1]--;//and a[i]-1 if it is present
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends