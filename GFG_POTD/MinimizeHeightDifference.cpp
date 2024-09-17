//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> arr, int k) {
        // code here
        
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int maxi = arr.back() - k;
        int mini = arr[0] + k;
        
        int ans =  arr.back() - arr[0];
        int i = 0;
        while(i < n - 1 && arr[i + 1] < k) i++;
        while(i < n - 1)
        {
            mini = min(arr[0] + k, arr[i + 1] - k);
            maxi = max(arr.back() - k, arr[i] + k);
            // cout<<i<<' '<<maxi<<' '<<mini<<endl;
            ans = min(ans, maxi - mini);
            i++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
