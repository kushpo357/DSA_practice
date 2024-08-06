//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        
        int countNum = 0;
        int n = str.size();
        int i = 0;
        while(i < n)
        {
            if(str[i] == '.')
                return false;
            string s = "";
            while(i < n && str[i] != '.')
            {
                if(!isdigit(str[i]))
                    return false;
                s.push_back(str[i]);
                i++;
            }
            
            int number = stoi(s);
            if(s != to_string(number))
                return false;
            
            if(number > 255 || number < 0)
                return false;
            
            countNum++;
            i++;
        }
        
        if(countNum != 4)
            return false;
            
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
