//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s)
    {
       //Your code here
       vector<vector<int>> v;
       
       for(int i = 0; i < s.size(); i++)
       {
           bool found = false;
           for(int j = 0; j < v.size(); j++)
           {
               if(v[j][0] == s[i] - 'a')
               {
                   found = true;
                   v[j][1]++;
                   break;
               }
           }
           if(!found) v.push_back({s[i] - 'a', 1});
       }
       
       for(int i = 0; i < v.size(); i++)
            if(v[i][1] == 1) return v[i][0] + 'a';
       return '$';
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends