//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        
        int mask = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            mask = mask ^ arr[i];
            mask = mask ^ (i + 1);
        }
        
        int lastsetbit = 1;
        mask = mask >> 1;
        while(mask)
        {
            mask = mask >> 1;
            lastsetbit = lastsetbit << 1;
        }
        
        int bigger = 0;
        int smaller = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(lastsetbit & (i + 1))
                bigger = bigger ^ (i + 1);
            else
                smaller = smaller ^ (i + 1);
                
            if(arr[i] & lastsetbit)
                bigger = bigger ^ arr[i];
            else
                smaller = smaller ^ arr[i];
        }
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == bigger)
                return {bigger, smaller};
            if(arr[i] == smaller)
                return {smaller, bigger};
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
