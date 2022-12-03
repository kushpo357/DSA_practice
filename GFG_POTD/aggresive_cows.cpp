//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        sort(stalls.begin(), stalls.end());
        
        int low = 1, high = stalls[n - 1] - stalls[0], ans = 0;
        while(low <= high)
        {
            int mid = low +(high - low)/2;
            
            if(Poss(mid, n, k, stalls))
            {
                low = mid + 1;
                ans = mid;
            }
            else
                high = mid - 1;
        }
        
        return ans;
    }
    
    bool Poss(int dis, int n, int k, vector<int> &arr)
    {
        int cow = arr[0], count = 1;
        
        for(int i = 1; i < n; i++)
        {
            if(arr[i] - cow >= dis)
            {
                count++;
                cow = arr[i];
            }
            
            if(count == k)
                return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends