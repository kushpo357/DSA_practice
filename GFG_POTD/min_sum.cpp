//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int n, vector<int> arr) {
        // code here
        multiset<int> ms;

        for(int i = 0; i < n; i++) ms.insert(arr[i]);
        int ans = 0;
        n--;
        while(n--)
        {
            int temp = *ms.begin() + *++ms.begin();
            ms.insert(temp);
            ms.erase(ms.begin());
            ms.erase(ms.begin());
            ans += temp;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends