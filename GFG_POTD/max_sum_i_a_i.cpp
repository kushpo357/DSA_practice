//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        
        long long currsum = 0, total  = 0, ans = 0;
        
        for(long long i = 0; i < n; i++)
        {
            currsum += i*a[i];
            total += a[i];
        }
        
        ans = currsum;
        
        for(long long i = 0; i < n; i++)
        {
            currsum = currsum - total + (long long)n*a[i];
            ans = max(ans, currsum);
        }
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends
