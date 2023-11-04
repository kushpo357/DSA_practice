//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) {
        // code here
        
        int l = 0, r = n - 1;
        int ans = -1;
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(arr[mid] == 0)
            {
                l = mid + 1;
            }
            else
            {
                ans = mid;
                r = mid - 1;
            }
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
