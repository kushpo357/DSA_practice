//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool check(const vector<int> &seq)
    {
        int level = seq.size() - 1; // Current level/row
        for(int i = 0; i < level; i++)
        {
            if(abs(seq[level] - seq[i]) == (level - i)) // Check diagonal conflicts
            {
                return false;
            }
        }
        return true;
    }

    void solve(vector<bool> &col, vector<vector<int>> &ans, const int &n, vector<int> &seq)
    {
        if(seq.size() == n)
        {
            ans.push_back(seq);
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(!col[i])
            {
                seq.push_back(i);
                if(check(seq))
                {
                    col[i] = true;
                    solve(col, ans, n, seq);
                    col[i] = false;
                }
                seq.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<bool> col(n, false);
        vector<int> seq;
        vector<vector<int>> ans;

        solve(col, ans, n, seq);

        for(int i = 0; i < ans.size(); i++)
        {
            for(int j = 0; j < n; j++)
            {
                ans[i][j]++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
