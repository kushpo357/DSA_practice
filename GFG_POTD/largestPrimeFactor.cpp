//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int n){
        // code here
        
        int ans = 0;
        int temp = n;
        for(int i = 2; i*i <= n; i++)
        {
            while(!(temp%i))
            {
                temp /= i;
                ans = i;
            }
        }
        if(temp != 1) ans = max(temp, ans);
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
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends