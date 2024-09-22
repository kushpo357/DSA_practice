//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        
        int n = str.size();
        vector<int> lps(n, 0);
        
        for(int i = 1, j = 0; i < n; i++)
        {
            if(str[i] == str[j])
            {
                j++;
                lps[i] = j;
            }
            else
            {
                if(j)
                {
                    j = lps[j - 1];
                    i--;
                }
                else lps[i] = 0;
            }
        }
        
        return lps[n - 1];
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends
