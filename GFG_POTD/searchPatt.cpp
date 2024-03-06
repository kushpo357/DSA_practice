//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            
            int n = text.size();
            int i = 0;
            vector<int> ans;
            
            for(int i = 0; i < n;)
            {
                i = text.find(pattern, i);
                
                if(i == string::npos) return ans;
                
                i++;
                ans.push_back(i);
                
            }
            
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
