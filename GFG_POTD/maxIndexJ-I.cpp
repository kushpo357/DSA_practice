//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    
    int maxIndexDiff(int a[], int n) 
    { 
        //Code here
        
        stack<int> st;
        
        for(int i = n - 1; i >= 0; i--)
        {
            while(st.empty() or a[i] > a[st.top()])
                st.push(i);
        }
        
        int ans = 0;
        int i = 0;
        while(i < n && !st.empty())
        {
            if(a[i] <= a[st.top()] && i <= st.top())
            {
                ans=max(ans, st.top() - i);
                st.pop();
            }
            else if(i > st.top()) st.pop();
            else i++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends
