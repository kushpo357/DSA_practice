//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	    static bool compare(string &a, string &b)
	    {
	        return a < b;
	    }
	    void findSub(const string &s, int i, const int &n, string temp, vector<string> &ans)
	    {
	        if(i == n) 
	        {
	            ans.push_back(temp);
	            return;
	        }
	        
	        findSub(s, i + 1, n, temp, ans);
	        temp.push_back(s[i]);
	        findSub(s, i + 1, n, temp, ans);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    
		    vector<string> ans;
		    int n = s.size();
		    for(int i = 0; i < n; i++)
		    {
		        string temp = "";
		        temp.push_back(s[i]);
		        findSub(s, i + 1, n, temp, ans);
		    }
		    
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
