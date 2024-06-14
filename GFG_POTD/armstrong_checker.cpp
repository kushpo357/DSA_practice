//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        
        int tempn = n;
        
        //first digit
        int first = tempn % 10;
        
        //second digit
        tempn = tempn / 10;
        int second = tempn % 10;
        
        //third digit
        tempn = tempn / 10;
        int third = tempn % 10;
        
        //sum of cubes
        int sum = pow(first, 3) + pow(second, 3) + pow(third, 3);
        
        //checking for armstrong number
        
        if(n == sum)
            return "true";
        
        return "false";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
