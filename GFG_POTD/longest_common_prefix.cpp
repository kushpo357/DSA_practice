//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        
        string common = "";
        int size = INT_MAX;
        int ind = -1;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            if(arr[i].size() < size)
            {
                ind = i;
                size = arr[i].size();
            }
        }
        
        common = arr[ind];
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(common[j] != arr[i][j])
                {
                    size = j;
                    break;
                }
            }
        }
        
        if(!size)
            return "-1";
            
        return common.substr(0, size);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends
