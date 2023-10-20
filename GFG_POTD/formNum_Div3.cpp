//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isPossible(int n, int arr[]) {
        // code here
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            int temp = arr[i];
            
            while(temp)
            {
                ans = (ans + (temp%10))%3;
                temp /= 10;
            }
        }
        
        if(!ans) return 1;
        
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
