//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        long long cost = 0;
        
        priority_queue <long long, vector<long long> , greater<long long>> que;
        
        for (int i = 0; i < n ; i++) que.push(arr[i]);
        
        long long min1, min2;
        
        while(que.size() > 1){\
        
            min1 = que.top();
            que.pop();
            
            min2 = que.top();
            que.pop();
            
            cost = min1 + min2 + cost;
            
            que.push(min1 + min2);
            
        }
        
        return cost;
        
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends