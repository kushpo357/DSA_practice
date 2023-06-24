//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    
    struct trienode
    {
      
      int charnum;
      struct trienode* alpha[26];
      
    };
    
    struct trienode* getnode()
    {
        struct trienode* node = new trienode;
        
        node->charnum = 0;
        
        for(int i = 0; i < 26; i++)
        {
            node->alpha[i] = NULL;
        }
        
        return node;
    }
    
    void addstring(string s, struct trienode* node)
    {
        int len = s.size();
        for(int i = 0; i < len; i++)
        {
            if(node->alpha[s[i] - 'a'] == NULL)
            {
                node->alpha[s[i] - 'a'] = getnode();
            }
            node = node->alpha[s[i] - 'a'];
            node->charnum++;
        }
    }
    
    int checknum(string s, int end, struct trienode* node)
    {
        for(int i = 0; i < end; i++)
        {
            if(node->alpha[s[i] - 'a'] == NULL) return 0;
            node = node->alpha[s[i] - 'a'];
        }
        
        return node->charnum;
    }
    
    int klengthpref(string arr[], int n, int k, string str){    
        
        struct trienode* node = getnode(), *temp;
        
        for(int i = 0; i < n; i++)
        {
            temp = node;
            addstring(arr[i], temp);
        }
        
        return checknum(str, k, node);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends