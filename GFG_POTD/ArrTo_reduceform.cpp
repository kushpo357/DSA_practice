//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    // code here
	    map <int,int> mp;
        for( int i=0;i<n;i++)
            mp[arr[i]]=i;
         
        unordered_map<int,int>mp1;
        int j=0;
        for(auto it = mp.begin(); it != mp.end(); ++it)
        {
            int s=it->first;
            mp1[s]=j;
            j++;
        }
        for( int i=0;i<n;i++)
        {
            if( mp1.find(arr[i])!=mp1.end())
                arr[i]=mp1[arr[i]];
        }
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends