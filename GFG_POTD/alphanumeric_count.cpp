//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct alphanumeric {
    string name;
    int count;
};
class Solution {
  public:
    vector<alphanumeric> sortedStrings(int N, vector<string> A) {
        // code here
        vector<alphanumeric> v;
        map<string, int> m;
        map<string, int> :: iterator it;
        for(int i = 0; i < N; i++)
        {
            it = m.find(A[i]);
            
            if(it == m.end())
                m.insert({A[i],1});
            else
                it->second += 1;
        }
        it = m.begin();
        while(it != m.end())
        {
            alphanumeric a;
            a.name = it->first;
            a.count = it->second;
            v.push_back(a);
            it++;
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
        cin.ignore();
        vector<string> v;
        for (int i = 0; i < N; i++) {
            string s;
            getline(cin, s);
            v.push_back(s);
        }
        Solution ob;
        vector<alphanumeric> ans = ob.sortedStrings(N, v);
        for (auto u : ans) cout << u.name << " " << u.count << "\n";
    }
}
// } Driver Code Ends