//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        int n = matrix.size(), m = matrix[0].size(), dir = 1;
        pair<int, int> prev, curr = {0,0};
        while(curr.first >=0 && curr.first < n && curr.second >= 0 && curr.second < m)
        {
            prev = curr;
            if(matrix[curr.first][curr.second])
            {
                if(dir++ == 3) dir = 0;
                matrix[curr.first][curr.second]--;
            }
            switch(dir)
            {
                case 0:
                        curr.first--;
                        break;
                case 1:
                        curr.second++;
                        break;
                case 2:
                        curr.first++;
                        break;
                case 3:
                        curr.second--;
                        break;
            }
        }
        
        return prev;
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends