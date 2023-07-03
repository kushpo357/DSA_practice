//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool isdescending(int arr[], int n)
    {
        for(int i = 0; i < n - 1 ; i++)
        {
            if(arr[i] < arr[i + 1]) return 0;
        }
        
        return 1;
    }
    int maxIndexDiff(int arr[], int n) {
        // code here
        int ans = 0;
        if(isdescending(arr, n)) return 0;
        int start = 0, prev = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] > prev) continue;
            int temp = 0;
            for(int j = i + ans; j < n; j++)
            {
                if(arr[j] >= arr[i]) ans = max(j - i, ans);
            }
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends