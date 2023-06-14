//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int a[], int n, int k) {
        // code here
        multiset<int> s;
        
        for(int i = 0; i < n; i++)
        {
            s.insert(a[i]);
        }
        long long ans = 0;
        for(int i = 0; i < k; i++)
        {
            auto it = s.end();
            it--;
            int temp = *it;
            ans += temp;
            s.erase(it);
            s.insert(temp/2);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends