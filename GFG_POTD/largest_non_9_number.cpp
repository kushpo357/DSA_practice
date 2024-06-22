//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
        int n = sentence.size();
        long long ans = -1;
        for(int i = 0; i < n; i++)
        {
            if(isdigit(sentence[i]))
            {
                int found9 = false;
                long long num = 0;
                int j = i;
                for(; j < n && isdigit(sentence[j]); j++)
                {
                    if(sentence[j] == '9')
                        found9 = true;
                        
                    num = num*10 + sentence[j] - '0';
                }
                
                if(found9)
                {
                    i = j;
                }
                else
                {
                    ans = max(ans, num);
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends
