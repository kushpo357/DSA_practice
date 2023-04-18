//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int tb=b;
        
        int bsetbits=0;
        while(tb>0)
        {
            if(tb&1) bsetbits++;
            tb>>=1;
        }
        
        int ta=a;
        int asetbits=0;
        
        while(ta>0)
        {
            if(ta&1) asetbits++;
            ta>>=1;
        }
        if(asetbits==bsetbits)
        {
            return a;
        }
        else if(asetbits>bsetbits)
        {
            int ans=0;
            int rem=bsetbits;
            for(int i=31;i>=0;i--)
            {
                if(a&(1<<i))
                {
                    ans|=(1<<i);
                    rem--;
                } 
                if(rem==0) return ans;
            }
        }
        else 
        {
            int rem=bsetbits-asetbits;
            int ans=a;
            for(int i=0;i<=31;i++)
            {
                if((a&(1<<i))==0)
                {
                    ans|=(1<<i);
                    rem--;
                } 
                if(rem==0) return ans;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends