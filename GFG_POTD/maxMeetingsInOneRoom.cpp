//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    static bool compare(vector<int> &a, vector<int> & b)
    {
        if(a[0] < b[0]) return 1;
        if(a[0] == b[0])
        {
            if(a[1] < b[1]) return 1;
        }
        
        return 0;
    }
    vector<int> maxMeetings(int n, vector<int> &s, vector<int> &f){
        
        vector<vector<int>> sortMeet(n, vector<int>(3, 0));
        
        for(int i = 0; i < n; i++)
        {
            sortMeet[i][0] = f[i];
            sortMeet[i][1] = s[i];
            sortMeet[i][2] = i;
        }
        
        sort(sortMeet.begin(), sortMeet.end(), compare);
        
        int prevtime = -1;
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++)
        {
            if(sortMeet[i][1] > prevtime)
            {
                ans.push_back(sortMeet[i][2] + 1);
                prevtime = sortMeet[i][0];
            }
        }
        
        sort(ans.begin(), ans.end());
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
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
