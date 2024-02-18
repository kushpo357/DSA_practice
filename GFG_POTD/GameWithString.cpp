//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        
        int n = s.size();
        
        vector<int> freq(26, 0);
        
        for(int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }
        
        vector<int> indValue;
        
        for(int i = 0; i < 26; i++)
        {
            //cout<<freq[i]<<endl;
            if(freq[i] != 0)
            {
                indValue.push_back(freq[i]);
            }
        }
        
        indValue.push_back(0);
        
        sort(indValue.begin(), indValue.end(), greater<int>());
        int nV = indValue.size();
        
        for(int i = 0; i < nV && k; i++)
        {
            for(int j = i - 1; j >= 0 && k; j--)
            {
                if(indValue[j] == indValue[i]) break;
                int temp = indValue[j] - indValue[i];
                indValue[j]--;
                k--;
            }
            if(i && indValue[i] != indValue[i - 1]) i--;
        }
        
        int ans = 0;
        for(int i = 0; i < nV; i++)
        {
            ans += indValue[i]*indValue[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
