//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        
        int n = nums.size();
        long long int pro = 1;
        
        int isZero = -1;
        vector<long long> ans(n, 0);
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
            {
                if(isZero != -1)
                    return ans;
                else
                {
                    isZero = i;
                    continue;
                }
            }
            pro *= nums[i];
        }
        
        if(isZero != -1)
        {
            ans[isZero] = pro;
            return ans;
        }
        
        for(int i = 0; i < n; i++)
        {
            ans[i] = (pro/nums[i]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
