//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        
        sort(a, a + n);
        sort(b, b + m);
        
        long long suma = 0;
        
        for(int i = 0; i < n; i++)
        {
            suma = suma + (long long)a[i];
        }
        
        long long sumb = 0;
        
        for(int i = 0; i < m; i++)
        {
            sumb = sumb + (long long)b[i];
        }
        
        
        int i = 0, j = 0;
        while(i < n && j < m)
        {
            if((suma - a[i] + b[j]) == (sumb - b[j] + a[i]))
                return 1;
            
            if((suma - a[i] + b[j]) < (sumb - b[j] + a[i]))
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
