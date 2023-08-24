//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
        int sign = 1;
        if (s1[0] == '-' and s2[0] == '-') 
        {
            s1.erase(s1.begin() + 0);
            s2.erase(s2.begin() + 0);
        } 
        else if (s1[0] == '-') 
        {
            s1.erase(s1.begin() + 0);
            sign = -1;
        } 
        else if (s2[0] == '-') 
        {
            s2.erase(s2.begin() + 0);
            sign = -1;
        }
    
        if (s1.size() < s2.size())
        {
            string tmp = s2;
            s2 = s1;
            s1 = tmp;
        }
    
        int n = s1.size();
        int m = s2.size();
    
        vector<int> v(n + m, 0);
        for (int i = m - 1; i >= 0; i--)
        {
            vector<int> tmp(n + m, 0);
            int carry1 = 0;
            int id;
            for (int j = n - 1; j >= 0; j--) 
            {
                int val = (s2[i] - '0') * (s1[j] - '0') + carry1;
                tmp[i + j + 1] = val % 10;
                carry1 = val / 10;
                id = j + i + 1;
            }
    
            if (carry1 > 0)
                tmp[id - 1] = carry1;
            
            int carry2 = 0;
            int id2;
            for (int k = n + m - 1; k >= 0; k--) 
            {
                int v1 = v[k];
                int v2 = tmp[k];
                int sum = v1 + v2 + carry2;
    
                v[k] = sum % 10;
                carry2 = sum / 10;
                id2 = k;
            }
    
            if (carry2 > 0) v[id2 - 1] = carry2;
        }

        string ans = "";
        int i = 0;
        while (i < v.size() && v[i] == 0)
            i++;
    
        for (int j = i; j < v.size(); j++)
            ans += to_string(v[j]);
    
        if (ans.size() == 0)
            ans = '0';
    
        if (sign == -1)
        {
            if (ans == "0")
                return ans;
    
            string nans = "-";
            nans += ans;
            return nans;
        }
    
        return ans;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends
