//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        
        int n1 = arr1.size(), n2 = arr2.size();
        
        int low = min(arr1[0], arr2[0]);
        int high = max(arr1[n1 - 1], arr2[n2 - 1]);
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            int ub = upper_bound(arr1.begin(), arr1.end(), mid) - arr1.begin();
            int lb = upper_bound(arr2.begin(), arr2.end(), mid) - arr2.begin();
            if(ub + lb < k) low = mid + 1;
            else high = mid - 1;
        }
        
        return low;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends
