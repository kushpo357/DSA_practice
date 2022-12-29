//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &a) {
        // code here
        vector<int> v;
        for(int i=0;i<n;i++) {
            //int x=a[i];
            if(v.empty()) {
                v.push_back(a[i]);
            }
            else if(v.back()<0 || a[i]>0) {
                v.push_back(a[i]);
            }
            else if(v.back() + a[i] ==0) {
                v.pop_back();
            }
            else if(v.back() + a[i] <0) {
                v.pop_back();
                i--;
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends