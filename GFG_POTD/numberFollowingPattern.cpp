//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        
        int n = s.size();
        int curr = 1;
        string ans = "";
        int i = 0;
        while(i < n)
        {
            if(s[i] == 'I')
            {
                ans.push_back(curr + '0');
                i++;
            }
            else
            {
                int temp = curr;
                while(i < n && s[i] == 'D')
                {
                    curr++;
                    i++;
                }
                for(int j = curr; j >= temp; j--)
                {
                    ans.push_back(j + '0');
                }
                i++;
            }
            curr++;
            //cout<<ans.back()<<endl;
        }
        
        //cout<<curr<<' '<<i<<endl;
        if(ans.size() < n + 1) ans.push_back(curr + '0');
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
