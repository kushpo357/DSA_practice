//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int n, int k, vector<char> &tasks) {
        // code here
        
        vector<int> v(26, 0);
        
        for(int i = 0; i < n; i++) v[tasks[i] - 'A']++;
        
        int maxfreq = 0, maxfreqnum = 0;;
        for(int i = 0; i < 26; i++)
        {
            if(maxfreq == v[i]) maxfreqnum++;
            if(maxfreq < v[i])
            {
                maxfreqnum = 1;
                maxfreq = v[i];
            }
        }
        
        return max(n, maxfreqnum + (maxfreq - 1)*(k + 1));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends