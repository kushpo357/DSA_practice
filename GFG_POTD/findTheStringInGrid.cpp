//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dirpos(vector<vector<char>> &grid, string &word,int i, int j, int diri, int dirj, int ind)
    {
        if(ind == word.size()) return true;
        i += diri;
        j += dirj;
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || word[ind] != grid[i][j]) 
            return false;
        
        return dirpos(grid, word, i, j, diri, dirj, ind + 1);
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    
	    int n = grid.size();
	    int m = grid[0].size();
	    int w = word.size(); 
	    vector<vector<int>> ans;
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < m; j++)
	        {
	            if(grid[i][j] == word[0])
	            {
	                bool possible = 0;
	                if(dirpos(grid, word, i, j, 1, 0, 1)) possible = 1;
	                else if(dirpos(grid, word, i, j, 0, 1, 1)) possible = 1;
	                else if(dirpos(grid, word, i, j, -1, 0, 1)) possible = 1;
	                else if(dirpos(grid, word, i, j, 0, -1, 1)) possible = 1;
	                else if(dirpos(grid, word, i, j, 1, 1, 1)) possible = 1;
	                else if(dirpos(grid, word, i, j, -1, -1, 1)) possible = 1;
	                else if(dirpos(grid, word, i, j, -1, 1, 1)) possible = 1;
	                else if(dirpos(grid, word, i, j, 1, -1, 1)) possible = 1;
	                
	                if(possible) ans.push_back({i, j});
	            }
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
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends
