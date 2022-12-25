//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
        // Code here

        int zi = -1, zj = -1;
        int n = matrix.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n;j++)
            {
                if(matrix[i][j] == 0)
                {
                    zj = j;
                    zi = i;
                    break;
                }
            }
        }

        long long sum = 0;
        if(zi != 0)
        {
            for(int i = 0; i < n; i++)
                sum += matrix[0][i];
        }
        else if(n > 0){
            for(int i = 0; i < n; i++)
                sum += matrix[1][i];
        }

        long long res = sum;

        for(int m = 0; m < n; m++)
            res -= matrix[zi][m];

        if(res <= 0)
            return -1;

        for(int i = 0 ; i < n; i++)
        {
            long long row_sum = 0;
            for(int j = 0; j < n; j++){
                if(zi == i && zj == j)
                    row_sum += res;
                else
                    row_sum += matrix[i][j];
            }

            if(row_sum != sum)
                return -1;

        }

        for(int i = 0; i < n; i++)
        {
            long long int col_sum = 0;

            for(int j = 0 ; j < n; j++)
            {
                if(zi == j && zj == i)
                    col_sum += res;
                else
                    col_sum += matrix[j][i];
            }

            if(col_sum != sum)
                return -1;
        }

        long long int diag_sum = 0;

        for(int i = 0; i < n; i++)
        {
            if(zi == i && zj == i)
                diag_sum += res;
            else
                diag_sum += matrix[i][i];
        }

        if(diag_sum != sum)
            return -1;

        diag_sum = 0;

        for(int i = 0 ; i < n; i++)
        {
            if(zi == n - 1 - i && zj == i)
                diag_sum += res;
            else
                diag_sum += matrix[n-1-i][i];
        }
        if(diag_sum != sum)
            return -1;

        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends