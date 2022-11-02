//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            if(!k)
                return n*m;
                
            set<int> row, col;
            for(int i = 0; i < k; i++)
            {
                row.insert(enemy[i][0]);
                col.insert(enemy[i][1]);
            }
            
            int rowCount = 0, colCount = 0;
            
            int rowNum = 0 , colNum = 0;
            
            for(set<int> :: iterator it = row.begin(); it != row.end(); it++)
            {
                rowCount = max(rowCount, *it - rowNum - 1);
                rowNum = *it;
            }
                
            rowCount = max(rowCount, (n - *--row.end()));
            
            for(set<int> :: iterator it = col.begin(); it != col.end(); it++)
            {
                colCount = max(colCount, *it - colNum - 1);
                colNum = *it;
            }
            
            colCount = max(colCount, (m - *--col.end()));
            
            return colCount*rowCount;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends