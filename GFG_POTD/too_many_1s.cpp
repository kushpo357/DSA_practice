//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

    string decimalToBinary(int n){
        string ans;
        while(n){
            int mod=n%2;
            ans=ans+to_string(mod);
            n=n/2;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
    
    int binaryToDecimal(string s){
        int cnt=0;
        int ans=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1')
                ans=ans+pow(2,cnt);
            cnt++;
        }
        return ans;
    }
    
    public:
    int noConseBits(int n) {
        // code here
        string temp=decimalToBinary(n);
        
        if(temp.size()>=3){
            for(int i=0;i<=temp.size()-3;i++){
                bool flag=1;
                for(int j=i;j<i+3;j++){
                    if(temp[j]=='0'){
                        flag=0;
                        break;
                    }
                }
                
                if(flag)
                   temp[i+2]='0'; 
            }
        }
        
        return binaryToDecimal(temp);
    }
};

//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends