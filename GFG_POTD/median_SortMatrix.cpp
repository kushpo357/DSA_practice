//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here
        int ans;
        int n = r*c;
        int mini = 0, maxi = 2000;
        while(mini <= maxi)
        {
            int count = 0;
            int mid = mini + (maxi - mini)/2;
            for(int i = 0; i < r; i++)
                count += upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();

            if(count < (n+1)/2)
                mini = mid + 1;
            else
            {
                ans = mid;
                maxi = mid - 1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends