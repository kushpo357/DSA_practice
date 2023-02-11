//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMinimumDays(int n,string s, vector<int> &p) {
        // code here
        int match = 0;
        for(int i = 0; i < n - 1; i++)
            if(s[i] == s[i + 1]) match++;
        
        if(match == 0) return 0;
        for(int i = 0; i < n; i++)
        {
            int j = p[i];
            if(j + 1 < n and s[j] == s[j + 1]) match--; // reduce match
            if(j >= 0 and s[j - 1] == s[j]) match--;
            s[j] = '?';
            if(!match) return i + 1;
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends