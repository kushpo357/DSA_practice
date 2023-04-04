//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    
    int count = 1;
    char prev = str[0];
    int n = str.size();
    
    for(int i = 0; i < n; i++)
    {
        if(str[i] != prev)
        {
            count++;
            prev = str[i];
        }
    }
    
    return (count/2) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends