//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    static bool Compare(pair<int, int> a, pair<int, int> b)
    {
        if(a.second == b.second)
            return a.first < b.first;
        
        return a.second > b.second;
    }
    vector<int> sortByFreq(vector<int> arr) {
        // Your code here
        
        int n = arr.size();
        
        map<int, int> freq;
        for(int i = 0; i < arr.size(); i++)
        {
            freq[arr[i]]++;
        }
        
        vector<pair<int, int>> v;
        
        for(int i = 0; i < n; i++)
        {
            v.push_back({arr[i], freq[arr[i]]});
        }
        
        sort(v.begin(), v.end(), Compare);
        for(int i = 0; i < n; i++)
        {
            arr[i] = v[i].first;
        }
        
        return arr;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
