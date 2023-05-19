//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        
        sort(range.begin(), range.end());
        vector<vector<int>> newrange;
        
        newrange.push_back({range[0][0], range[0][1]});
        int ind = 0;
        for(int i = 1; i < n; i++)
        {
            if(range[i][0] <= newrange[ind][1])
            {
                if(range[i][1] <= newrange[ind][1]) continue;
                newrange[ind][1] = range[i][1];
            }
            else
            {
                newrange.push_back({range[i][0], range[i][1]});
                ind++;
            }
        }
        
        int len = newrange.size();
        vector<int> ans;
        for(int i = 0; i < q; i++)
        {
            int currans = -1;
            for(int j = 0; j < len; j++)
            {
                if(newrange[j][1] - newrange[j][0] + 1 >= queries[i]) 
                {
                    currans = newrange[j][0] - 1 + queries[i];
                    break;
                }
                
                queries[i] -= (newrange[j][1] - newrange[j][0] + 1);
            }
            ans.push_back(currans);
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
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends