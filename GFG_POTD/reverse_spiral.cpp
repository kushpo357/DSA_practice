//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        int count = 0, trav = 0, i = 0, j = 0;
        vector<int> v;
        int sp = 2;
        int num = R*C;
        while(count < num)
        {
            switch(sp)
            {
                case 1:
                    if(i == trav)
                        sp = 2;
                    else
                    {
                        v.push_back(a[i][j]);
                        count++;
                        i--;
                    }
                    break;
                case 2:
                    if(j == C - trav - 1)
                        sp = 3;
                    else
                    {
                        v.push_back(a[i][j]);
                        count++;
                        j++;
                    }
                    break;
                case 3:
                    if(i == R - trav - 1)
                        sp = 4;
                    else
                    {
                        v.push_back(a[i][j]);
                        count++;
                        i++;
                    }
                    break;
                case 4:
                    if(j == trav)
                    {
                        sp = 1;
                        trav++;
                    }
                    else
                    {
                        v.push_back(a[i][j]);
                        count++;
                        j--;
                    }
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends