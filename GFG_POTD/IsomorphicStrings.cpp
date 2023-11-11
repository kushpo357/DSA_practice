//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
       
       map<char, char> mp;
       
       if(str1.size() != str2.size())
        return false;
        
        int n = str1.size();
        
        vector<int> v(27, 27);
        vector<bool> vis(27, 0);
        
        for(int i = 0; i < n; i++)
        {
            if(v[str1[i] - 'a'] == 27)
            {
                if(vis[str2[i] - 'a']) return false;
                v[str1[i] - 'a'] = str2[i] - 'a';
                vis[str2[i] - 'a'] = true;
            }
            
            if(v[str1[i] - 'a'] != str2[i] - 'a')
                return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
