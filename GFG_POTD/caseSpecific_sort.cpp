//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        // your code here
        string strl, stru;
        
        for(int i = 0; i < n; i++)
        {
            if(isupper(s[i]))
                strl.push_back(s[i]);
            else
                stru.push_back(s[i]);
        }
        
        sort(strl.begin(), strl.end(), greater<int>());
        sort(stru.begin(), stru.end(), greater<int>());
        
        for(int i = 0; i < n; i++)
        {
            if(isupper(s[i]))
            {
                s[i] = strl.back();
                strl.pop_back();
            }
            else
            {
                s[i] = stru.back();
                stru.pop_back();
            }
        }
        
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends