//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.

int check(int x, int y, int n, int m)
{
    int ans = 8;
    if(x - 2 < 0 || y + 1 >= m)
        ans--;
    if(x - 2 < 0 || y - 1 < 0)
        ans--;
    if(x + 2 >= n || y + 1 >= m)
        ans--;
    if(x + 2 >= n || y - 1 < 0)
        ans--;
    if(x - 1 < 0 || y + 2 >= m)
        ans--;
    if(x + 1 >= n || y - 2 < 0)
        ans--;
    if(x - 1 < 0 || y + 2 >= m)
        ans--;
    if(x + 1 >= n || y - 2 < 0)
        ans--;
    
    return ans;
}
long long numOfWays(int n, int m)
{
    // write code here
    long long ans = 0, MOD = 1000000007;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            ans = ((ans)%MOD + (n*m)%MOD  - 1 - check(i, j, n, m))%MOD;
    }
    
    return ans;
}