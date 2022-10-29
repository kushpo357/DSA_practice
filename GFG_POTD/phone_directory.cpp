//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> ans;
        Trie t;
        for(int i = 0; i < n; i++)
            t.insert(contact[i]);
        for(int i = 0; i< s.length(); i++)
            ans.push_back(t.Ans(s.substr(0, i + 1)));
        return ans;
    }
    struct TrieNode
    {
        
        TrieNode* alpha[26];
        bool isEnd;
        TrieNode(){
            for(int i=0; i<26; i++)
                alpha[i]=NULL;
            isEnd=false;
        }
    };
    
    class Trie{
        TrieNode* root;
      public:
        Trie()
        {
            root = new TrieNode();
        }
        void insert(string key)
        {
            struct TrieNode* currNode = root;
            for(int i = 0; i < key.size(); i++)
            {
                int ind = key[i] - 'a';
                
                if(currNode->alpha[ind] == NULL)
                    currNode->alpha[ind] = new TrieNode();
                    
                currNode = currNode->alpha[ind];
            }
            currNode->isEnd = true;
        }
        vector<string> Ans(string key)
        {
            vector<string> v;
            TrieNode* currNode = root;
            for(int i = 0; i < key.size(); i++)
            {
                if(currNode->alpha[key[i] - 'a'] == NULL)
                {
                    v.push_back("0");
                    return v;
                }
                currNode = currNode->alpha[key[i] - 'a'];
            }
            search(key,currNode,v);
            return v;
        }
        void search(string key, TrieNode* root, vector<string> &v)
        {
            if(root->isEnd == true)
                v.push_back(key);
            for(int i = 0; i < 26; i++)
            {
                if(root->alpha[i] != NULL)
                {
                    key.push_back('a' + i);
                    search(key,root->alpha[i],v);
                    key.pop_back();
                }
            }
            
        }
    };
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends