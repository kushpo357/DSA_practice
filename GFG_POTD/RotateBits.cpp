//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            //code here
            int leftRotation = (n<<(d%16))%(1<<16) + (n>>(16 - (d%16)));
            int rightRotation = ((n%(1<<(d%16)))<<(16 - (d%16))) + (n>>(d%16)); 
            return{leftRotation, rightRotation};
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
