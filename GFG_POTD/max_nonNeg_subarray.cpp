//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    vector<vector<int>> v;
	    
	    for(int i = 0; i < n; i++)
	    {
	        vector<int> temp;
	        if(a[i] >= 0)
	        {
	            while(a[i] >= 0 && i < n)
	            {
	                temp.push_back(a[i]);
	                i++;
	            }
	            v.push_back(temp);
	        }
	    }
	    
	    if(v.empty())
	    {
	        vector<int> ans;
	        ans.push_back(-1);
	        return ans;
	    }
	    
	    int ans = 0, maxsum = INT_MIN, sans = 0;
	    
	    for(int i = 0; i< v.size(); i++)
	    {
	        int si = v[i].size();
	        int currsum = 0;

	        for(int j = 0; j < si; j++)
	            currsum += v[i][j];
	        
	        if(currsum > maxsum)
	        {
	            maxsum = currsum;
	            ans = i;
	            sans = si;
	        }
	        else if(currsum == maxsum)
	        {
	            if(si > sans)
	                ans = i;
	            else if(si == sans)
	                ans = min(i, ans);
	        }
	    }
	    
	    return v[ans];
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends