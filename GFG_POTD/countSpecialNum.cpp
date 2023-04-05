//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> arr) {
        // Code here
        vector<int> v(n, 0);
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++)
        {
            if(v[i]) continue;
            
            for(int j = i + 1; j < n; j++)
            {
                if(!(arr[j] % arr[i])) v[j] = 1;
                if(arr[j] == arr[i]) v[i] = 1;
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
            if(v[i]) ans++;
            
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends