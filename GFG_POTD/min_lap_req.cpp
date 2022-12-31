//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int n, int start[], int end[]) {
        // Code here
        vector<int> s, e;
        
        for(int i = 0; i < n; i++)
        {
            s.push_back(start[i]);
            e.push_back(end[i]);
        }
        
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        
        int ans = 1;
        
        for(int i = 1, j = 0; i < n && j < n; i++)
        {
            if(s[i] < e[j]) ans++;
            else j++;
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
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends