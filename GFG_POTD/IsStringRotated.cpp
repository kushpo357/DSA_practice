//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        
        if(str1.size() != str2.size())
            return false;
            
        int n = str1.size();
        
        bool ans = true;
        for(int i = 0; i < n; i++)
        {
            if(str1[i] != str2[(i + 2)%n])
            {
                ans = false;
                break;
            }
        }
        
        if(ans == true) return true;
        
        ans = true;
        
        for(int i = 0; i < n; i++)
        {
            if(str2[i] != str1[(i + 2)%n])
            {
                ans = false;
                break;
            }
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
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends
