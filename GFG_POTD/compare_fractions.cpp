//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int stringToint(string str, int l, int r)
    {
        int num = 0;
        
        for(int i = l; i <= r; i++)
        {
            num = num*10 + str[i] - '0';
        }
        
        return num;
    }
    string compareFrac(string str) {
        // Code here
        
        int l = 0, r = 0;
        int n = str.size();
        
        while(str[r + 1] != '/')
        {
            r++;
        }
        
        int a = stringToint(str, l, r);
        
        l = r + 2;
        r = l;
        
        
        while(str[r + 1] != ',')
        {
            r++;
        }
        
        int b = stringToint(str, l, r);
        
        string frac1 = str.substr(0, r + 1);
        
        l = r + 3;
        r = l;
        
        string frac2 = str.substr(r, n - r);
        
        while(str[r + 1] != '/')
        {
            r++;
        }
        int c = stringToint(str, l, r);
        
        l = r + 2;
        r = l;
        
        int d = stringToint(str, l, n - 1);
        
        
        if(a*d == b*c)
            return "equal";
        
        if(a*d > b*c)
            return frac1;
            
        return frac2;
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends
