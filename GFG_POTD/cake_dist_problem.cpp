//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int maxSweetness(vector<int>& sweetness, int n, int k) {
    // Write your code here.
    int left = 1;
    int right = 0;
    for(int i = 0; i < n; i++) right += sweetness[i];
    
    while (left < right)
    {
        int mid = left + (right + 1 - left)/ 2;
        int pieces = 0;
        int currSweet = 0;
        
        for (int i = 0; i < n; i++) 
        {
            currSweet += sweetness[i];
            if (currSweet >= mid) 
            {
                pieces++;
                currSweet = 0;
            }
        }
        
        if (pieces > k) left = mid;
        else right = mid - 1;
        
    }
    
    return left;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends