//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
  
    int sumOfDigits(int n)
    {
        int sum = 0;
        
        while(n)
        {
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
    
    string even(int n)
    {
        if(n > 26)
            return even(26) + even(n - 26);
        
        string s = "";
        for(int i = 0; i < n/2; i++)
            s.push_back('a' + i);
            
        for(int i = 26 - n/2; i < 26; i++)
            s.push_back('a' + i);
            
        return s;
    }
    
    string oddDigOdd(int n)
    {
        if(n > 26)
            return even(26) + oddDigOdd(n - 26);
        
        string s = "";
        
        for(int i = 0; i < (n - 1)/2; i++)
                s.push_back('a' + i);
            
        for(int i = 26 - (n + 1)/2; i < 26; i++)
            s.push_back('a' + i);
            
        return s;
    }
    
    string oddDigEven(int n)
    {
        if(n > 26)
            return even(26) + oddDigEven(n - 26);
            
        string s = "";
        
        for(int i = 0; i < (n + 1)/2; i++)
                s.push_back('a' + i);
            
        for(int i = 26 - (n - 1)/2; i < 26; i++)
            s.push_back('a' + i);
        
        return s;
    }
    string BalancedString(int n) {
        // code here
        
        if(n & 1)
        {
            if(sumOfDigits(n) & 1)
                return oddDigOdd(n);
            
            return oddDigEven(n);
        }
        
        return even(n);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends