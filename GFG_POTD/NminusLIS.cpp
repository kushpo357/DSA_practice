//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int a[], int n) {
        // code here
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i = 1; i < n; i++)
        {
            if(a[i] > ans.back())
                ans.push_back(a[i]);
            else
            {
                int ind = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[ind] = a[i];
            }
        }
        
        return n - ans.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends