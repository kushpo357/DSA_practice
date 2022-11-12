//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		    int maxi = 0, n = s.size(), ans = 0;
		    unordered_map<char, int> m;
		    
		    for(int i = 0, j = 0; j < n; j++)
		    {
		        m[s[j]]++;
		        maxi = max(maxi, m[s[j]]);
		        int len = j - i + 1;
		        
		        if(len - maxi <= k)
		            ans = max(ans, len);
		        else
		        {
		            m[s[i]]--;
		            i++;
		        }
		    }
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
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends