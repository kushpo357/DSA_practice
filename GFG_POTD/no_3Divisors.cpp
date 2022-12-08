//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int numPrime(long long n){
        
        n=sqrt(n);
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
     
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        
         int count=0;
            for (int p = 2; p <= n; p++){
                if (prime[p])
                    count++;
            }
            return count;
            
        }

    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int> v;
        for(int i = 0; i < q; i++)
        {
            v.push_back(numPrime(query[i]));
        }
        
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends