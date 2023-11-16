//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
unordered_set<int>exist;
    int basePow;
    int total;
    bool backtr(string &s,int curHash,int k){
        if(exist.size()==total) return 1;
        for(int dig = 0;dig<k;dig++){
            int newHash = curHash*(k+1)+dig+1;
            if(exist.insert(newHash).second){
                s+='0'+dig;
                // cout<<s<<" kj "<<exist.size()<<endl;
                if(backtr(s,newHash%basePow,k)) return 1;
                s.pop_back();
                exist.erase(newHash);
            }
        }
        return 0;
    }
    
public:
    string findString(int n, int k) {
        basePow = pow(k+1,n-1);
        total = pow(k,n);
        exist.clear();
        string temp = string(n-1,'0');
        int curHash = n>1;
        for(int i = 0;i<n-2;i++) curHash = curHash*(k+1) + 1;
        backtr(temp,curHash,k);
        // cout<<temp<<endl;
        return temp;
        // code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
} 
// } Driver Code End
