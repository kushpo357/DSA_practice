//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        // code here...
        
        int s = 0, e = 0;
        int ans = arr[0];
        int sum = 0;
        int n = arr.size();
        while(e < n)
        {
            if(sum < 0)
            {
                sum -= arr[s];
                s++;
                if(e == s)
                {
                    sum = arr[e];
                    e++;
                }
            }
            else
            {
                sum += arr[e];
                e++;
            }
            ans = max(ans, sum);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends
