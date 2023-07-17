//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string a){
		    // Code here
		    
		    vector<vector<int>> v;
		    string ans = "";
		    for(int i = 0; i < a.size(); i++)
		    {
		        bool check = false;
		        for(int j = 0; j < v.size(); j++)
		        {
		            if(v[j][0] == a[i] - 'a')
		            {
		                v[j][1]++;
		                check = true;
		            }
		        }
		        if(!check) v.push_back({a[i] - 'a', 1});
		        char c = '#';
		        for(int j = 0; j < v.size(); j++)
		        {
		            if(v[j][1] == 1)
		            {
		                c = v[j][0] + 'a';
		                break;
		            }
		        }
		        ans.push_back(c);
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends