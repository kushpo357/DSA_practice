//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // code here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        vector<int> ans;
        
        priority_queue<pair<int,pair<int,int>>> pq;
        
        set<pair<int,int>> s;
        
        pq.push({a.back() + b.back(), {n - 1, n - 1}});
        
        s.insert({n - 1, n - 1});
        
        while(k--)
        {
            
            auto p = pq.top();
            int sum = p.first;
            int i = p.second.first;
            int j = p.second.second;
            
            ans.push_back(sum);
            pq.pop();
            
            if(s.find({i - 1, j}) == s.end())
            {
                pq.push({a[i - 1] + b[j], {i - 1, j}});
                s.insert({i - 1, j});
            }
            if(s.find({i, j - 1}) == s.end())
            {
                pq.push({a[i] + b[j - 1], {i, j - 1}});
                s.insert({i, j - 1});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
