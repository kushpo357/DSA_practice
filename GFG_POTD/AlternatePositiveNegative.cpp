//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        
        vector<int> posi, negi;
        int n = arr.size();
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] >= 0)
                posi.push_back(arr[i]);
            else
                negi.push_back(arr[i]);
        }
        
        int j = 0, k = 0, posn = posi.size(), negin = negi.size();
        
        int i = 0;
        
        while(i < n)
        {
            if(i & 1)
            {
                if(j == negin)
                    break;
                arr[i] = negi[j];
                j++;
            }
            else
            {
                if(k == posn)
                    break;
                arr[i] = posi[k];
                k++;
            }
            i++;
        }
        
        while(j < negin)
        {
            arr[i] = negi[j];
            i++;
            j++;
        }
        while(k < posn)
        {
            arr[i] = posi[k];
            i++;
            k++;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
