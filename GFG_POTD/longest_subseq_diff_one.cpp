//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        // code here
        
        vector<int> dp(n + 1, 1);
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = n - 1; j > i; j--)
            {
                if(abs(a[j] - a[i]) == 1)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends
