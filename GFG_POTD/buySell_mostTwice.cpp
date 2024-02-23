//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            //Write your code here..
            
            int n = price.size();
            
            vector<int> willbesold(n + 1, 0);
            
            int maxtosell = 0;
            for(int i = n - 1; i >= 0; i--)
            {
                maxtosell = max(maxtosell, price[i]);
                willbesold[i] = max(willbesold[i + 1], maxtosell - price[i]);
            }
            
            vector<int> wassold(n, 0);
             
            wassold[0] = 0;
            
            int mintopurchase = price[0];
            for(int i = 1; i < n; i++)
            {
                mintopurchase = min(mintopurchase, price[i]);
                wassold[i] = max(price[i] - mintopurchase, wassold[i - 1]);
            }
            
            int ans = 0;
            
            for(int i = 0; i < n; i++)
            {
                
                ans = max(ans, wassold[i] + willbesold[i + 1]);
            }
            
            return ans;
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends
