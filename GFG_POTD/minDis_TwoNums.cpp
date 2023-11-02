//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        
        int i = 0, j = 0;
        int ans = INT_MAX;
        
        while(i < n && j < n)
        {
            while(j < i)
            {
                if(a[j] == y)
                {
                    ans = min(ans, i - j);
                }
                j++;
            }
            
            while(a[j] != y && j < n) j++;
            
            if(j >= n) break;
            
            while(i < j)
            {
                if(a[i] == x)
                {
                    ans = min(ans, j - i);
                }
                i++;
            }
            
            while(a[i] != x && i < n) i++;
            
            if(i >= n) break;
        }
        
        if(ans == INT_MAX) return -1;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends
