//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        
        int i = 0, j = 0, k = 0;
        int n = arr.size();
        
        //sorting zeros and non zeros
        // one pointer for zeros and another for non zeros
        while(j < n)
        {
            while(i < n && arr[i] == 0) i++;
            if(i == n)
                return;
            j = i + 1;
            while(j < n && arr[j] != 0) j++;
            if(j == n)
                break;
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        
        if(i == n)
            return;
        
        //sorting 1s and 2s
        //one pointer for 1s and another for 2s
        //initialinzing pointer for 1 with the end of zeros
        j = i;
        
        while(k < n)
        {
            while(j < n && arr[j] == 1) j++;
            if(j == n)
                return;
            
            k = j + 1;
            while(k < n && arr[k] == 2) k++;
            if(k == n)
                return;
                
            swap(arr[j], arr[k]);
            j++;
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

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
