//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  
    int digitsum(int n)
    {
        int sum = 0;
        
        while(n)
        {
            sum += n % 10;
            n /= 10;
        }
        
        return sum;
    }
    
    void seive(vector<bool> &prime, int n)
    {
        //prime[1] == 1;
        for (int p = 2; p * p <= n; p++) 
        {
            if (prime[p] == true) 
            { 
                for (int i = p * p; i <= n; i += p) 
                    prime[i] = false; 
            } 
        }
    }
    
    int smithNum(int n) {
        // code here
        
        int dsum = digitsum(n);
        
        vector<bool> prime(n + 1, 1);
        
        seive(prime, n);
        
        int facsum = 0;
        
        prime[1] = prime[0] = false;
        
        if(prime[n]) return 0;
        
        //if()
        
        for(int i = 1; i <= n; i++)
        {
            if(prime[i] && n % i == 0)
            {
                while(n % i == 0)
                {
                    n /= i;
                    facsum += digitsum(i);
                    //cout<<facsum<<endl;
                }
            }
        }
        
        //cout<<facsum<<' '<<dsum<<endl;
        if(facsum == dsum) return 1;
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
