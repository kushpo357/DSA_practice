//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int maxMeetings(int n, int start[], int end[]) {
        //code here
        vector<pair<int, int>> meet(n);
        
        for (int i = 0; i < n; i++)
            meet[i] = {end[i], start[i]};
        
        sort(meet.begin(), meet.end());
        
        int count = 1;
        int lastTime = meet[0].first;
        
        for (int i = 1; i < n; i++) 
        {
            if (meet[i].second > lastTime) 
            {
                count++;
                lastTime = meet[i].first;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
