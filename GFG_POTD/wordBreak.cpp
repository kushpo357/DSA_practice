//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    int checker(int n, string s, vector<string> &dict)
    {
        int ns = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int dIs = dict[i].size();
            
            if(dIs > ns) continue;
            bool pos = true;
            int j = 0;
            for(; j < dIs; j++)
            {
                if(s[j] != dict[i][j])
                {
                    if(s[j] < dict[i][j]) return ans;
                    else 
                    {
                        pos = false;
                        break;
                    }
                }
            }
            
            if(pos)
            {
                if(j == ns) return 1;
                string temp = s.substr(j, ns - j);
                ans = checker(n, temp, dict);
                if(ans) return 1;
            }
        }
        
        return 0;
    }
    static bool myCmp(string s1, string s2)
    {
        return s1 < s2;
    }
    int wordBreak(int n, string s, vector<string> &dict) {
        //code here
        
        sort(dict.begin(), dict.end(), myCmp);
        return checker(n, s, dict);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends
