//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool ispivot(int mid, vector<int> & arr, int n)
    {
        if(mid == 0 && arr[0] >= arr[1])
            return true;
            
        if(mid == n - 1 && arr[n - 2] <= arr[n - 1])
            return true;
        
        if(arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1])
            return true;
        
        return false;
    }
    int search(vector<int>& arr, int key) {
        // complete the function here
        
        int p = 0;
        int n = arr.size();
        int l = 0, r = n - 1;
        
        if(n == 1 && arr[0] != key) return -1;
        
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(ispivot(mid, arr, n))
            {
                p = mid;
                break;
            }
            else if(arr[0] > arr[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        l = 0;
        r = p;
        
        while(l <= r)
        {
            int mid = l+ (r - l)/2;
            if(arr[mid] == key)
                return mid;
            else if(arr[mid] > key)
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        l = p + 1;
        r = n - 1;
        while(l <= r)
        {
            int mid = l+ (r - l)/2;
            if(arr[mid] == key)
                return mid;
            else if(arr[mid] > key)
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends
