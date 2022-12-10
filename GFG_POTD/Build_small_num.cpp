//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    string ans;
    int n = num.size();
    ans.push_back(num[0]);
    
    for(int i = 1; i < n; i++)
    {
        while(ans.back() > num[i] && k && !ans.empty())
        {
            ans.pop_back();
            k--;
        }
            
        ans.push_back(num[i]);
    }
    
    while(k)
    {
        ans.pop_back();
        k--;
    }
    
    if(ans[0] == '0')
    {
        int i = 0;
        int len = ans.size();
        while(ans[i] == '0' && i < len)
            i++;
        
        if(i == len)
            return "0";

        ans.erase(0,i);
    }
    
    return ans;
}