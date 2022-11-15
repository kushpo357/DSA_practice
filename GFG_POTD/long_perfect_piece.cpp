//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int n) {
        // code here
        multiset<int> m;

        int i = 0 , s = 0, ans = 0;
        
        while(i < n)
        {
            m.insert(arr[i++]);
            
            while(*m.rbegin() - *m.begin() > 1)
                m.erase(m.find(arr[s++]));
                
            ans = max(ans, i - s);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends