//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    static bool compare(string s1, string s2)
    {
        return s1[0] < s2[0];
    }
    bool isPalindrome(string s)
    {
        for(int i = 0, j = s.size() - 1; i <= j; i++, j--)
        {
            if(s[i] != s[j]) return 0;
        }
        return 1;
    }
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        
        sort(arr.begin(), arr.end());
        vector<string> v;
        
        for(int i = 0; i < n; i++)
        {
            string s;
            for(int j = arr[i].size() - 1; j >= 0; j--) s.push_back(arr[i][j]);
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        
        int palNum = 0;
        for(int i = 0; i < n; i++)
            if(isPalindrome(arr[i])) palNum++;
            
            
        if(!(palNum%2) && palNum) return 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < arr[i].size(); j++)
                if(v[i][j] != arr[i][j]) return 0;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends