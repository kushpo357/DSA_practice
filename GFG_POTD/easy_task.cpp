//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int stringToNum(string s)
    {
        int num = 0;
        for(int i = 0; s[i]!= 0; i++)
        {
            num = 10*num + s[i] - 48;
        }
        return num;
    }
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        // Code here
        vector<char> ans;
        for(int i = 0; i < q; i++)
        {
            if(queries[i][0] == "1")
            {
                s[stringToNum(queries[i][1])] = queries[i][2][0];
            }
            else
            {
                int v[26] = {0};
                int left = stringToNum(queries[i][1]), right = stringToNum(queries[i][2]);
                for(int j = left; j <= right; j++)
                {
                    v[s[j] - 97]++;
                }
                int k = stringToNum(queries[i][3]);
                for(int l = 25; l >= 0; l--)
                {
                    k -= v[l];
                    char ch = 'a';
                    ch += l;
                    if(k <= 0)
                    {
                        ans.push_back(ch);
                        break;
                    }
                }
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
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends