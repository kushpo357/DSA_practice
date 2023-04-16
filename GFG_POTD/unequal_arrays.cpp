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
    long long solve(int n, vector<int> &a, vector<int> &b) {
        // code here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int ans = 0;
        long long pos = 0, neg = 0;
        
        vector<int> aeven, aodd, beven, bodd;
        
        for(int i = 0; i < n; i++)
        {
            if(a[i] & 1) aodd.push_back(a[i]);
            else aeven.push_back(a[i]);
            if(b[i] & 1) bodd.push_back(b[i]);
            else beven.push_back(b[i]);
        }
        
        if(aeven.size() != beven.size() || aodd.size() != bodd.size()) return - 1;
            
        for(int i = 0; i < aeven.size(); i++)
        {
            long long diff = aeven[i] - beven[i];
            if(diff < 0) neg += abs(diff);
            else pos += diff;
        }
        for(int i = 0; i < aodd.size(); i++)
        {
            long long diff = aodd[i] - bodd[i];
            if(diff < 0) neg += abs(diff);
            else pos += diff;
        }
        if(pos != neg) return -1;
        
        return (long long)pos/2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends