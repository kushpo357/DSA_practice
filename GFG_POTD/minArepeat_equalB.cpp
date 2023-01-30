//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        // code here
        
        int i = 0, j = 0;
        int lena = a.length(), lenb = b.length();
        while(i < lena)
        {
            if(b[0] == a[i])
                break;
                
            i++;
        }
        if(i == lena)
            return -1;
        
        
        int ans = 1;
        while(j < lenb)
        {
            if(b[j] != a[i])
            return -1;
            
            j++;
            
            if(++i == lena)
            {
                i %= lena;
                ans++;
            }
        }
        if(i == 0 && j == lenb)
            ans--;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends