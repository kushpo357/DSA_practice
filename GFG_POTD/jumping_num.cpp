//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long x) {
        // code here
        if(x <= 9)
            return x;
            
        queue<long long> q;
        
        for(int i = 1; i < 10; i++)
            q.push(i);
        
        while(!q.empty())
        {
            long long num = q.front(), numg, nums;
            q.pop();
            
            if(num % 10 == 0)
            {
                numg = num*10 + 1;
                if(numg <= x)
                    q.push(numg);
            }
            else if(num % 10 == 9)
            {
                nums = num*10 + 8;
                if(nums <= x)
                    q.push(nums);
            }
            else
            {
                numg = num*10 + (num%10) + 1;
                nums = num*10 + (num%10) - 1;
                    
                if(nums > x)
                    return q.back();
                q.push(nums);
                
                if(numg > x)
                    return q.back();
                q.push(numg);
            }
        }
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends