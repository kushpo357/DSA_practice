//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(vector<vector<char>>& board, int n, int m, int i, int j, string &word, int len, int ind)
    {
        if(ind == len) return 1;
        if(i < 0 || j < 0 || i >= n || j >= m) return 0;
        if(word[ind] != board[i][j]) return 0;
        
        char ch = board[i][j];
        board[i][j] = '0';
        bool exist;
        exist = dfs(board, n, m, i + 1, j, word, len, ind + 1);
        if(exist) return 1;
        exist = dfs(board, n, m, i - 1, j, word, len, ind + 1);
        if(exist) return 1;
        exist = dfs(board, n, m, i, j + 1, word, len, ind + 1);
        if(exist) return 1;
        exist = dfs(board, n, m, i, j - 1, word, len, ind + 1);
        if(exist) return 1;
        board[i][j] = ch;
        return 0;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n = board.size();
        int m = board[0].size();
        int len = word.size();
        bool exist = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == word[0] && !exist)
                    exist = dfs(board, n, m, i, j, word, len, 0);
                    
                if(exist) return 1;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends