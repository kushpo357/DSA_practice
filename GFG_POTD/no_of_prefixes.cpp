//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
struct Node
{
    Node* links[26];
    int number[26] = {0};
    
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    
    void put(char ch, Node* node) 
    {
        links[ch - 'a'] = node;
        number[ch - 'a'] = 1;
    }
    
    Node* get(char ch)
    {
        return links[ch - 'a'];
    }
    
    void increaseNum(char ch)
    {
        number[ch - 'a']++;
    }
    
    int getNum(char ch)
    {
        return number[ch - 'a'];
    }
    
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
        
    }
    
    void insert(string word) 
    {
        Node* node = root;
        
        for(int i = 0; i < word.length(); i++)
        {
            
            if(!node -> containsKey(word[i]))
            {
                node -> put(word[i], new Node());
            } 
            else
             node -> increaseNum(word[i]);
             
            node = node -> get(word[i]);
        }
    }
    
    int takeAns(string word)
    {
        int ans = 0;
        
        Node* node = root;
        
        for(int i = 0; i < word.size(); i++)
        {
            if(!node -> containsKey(word[i])) 
                return 0;
            else 
                ans = node -> getNum(word[i]);
            
             node = node -> get(word[i]);
        }
        
        
        return ans;
    }
};

class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        // code here
        Trie trie;
        
        for(int i = 0; i < N; i++)
            trie.insert(li[i]);
            
        vector<int> ans(Q);
        
        for(int i = 0; i < Q; i++)
            ans[i] = trie.takeAns(query[i]);
            
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int Q, N, i = 0, x;
	    cin>>N;
	    string s;
	    string li[N];
	    for(int i = 0;i < N;i++)
	        cin>>li[i];
	    cin>>Q; 
	    x = Q;
	    string query[Q];
	    while(Q--){
	        cin>>s;
	        query[i++] = s;
	    }
	    
	    Solution ob;
	    vector<int> ans = ob.prefixCount(N, x, li, query);
	    for(auto i: ans) 
	        cout<<i<<"\n";
    }
    return 0;
}
// } Driver Code Ends