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
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        
        vector<vector<int>> maxmin(n, vector<int> (4, 0));
        
        maxmin[0][0] = arr[0];
        maxmin[0][1] = arr[0];
        maxmin[n - 1][2] = arr[n - 1];
        maxmin[n - 1][3] = arr[n - 1];
        for(int i = 1; i < n; i++)
        {
            maxmin[i][0] = max(maxmin[i - 1][0], arr[i]);
            maxmin[i][1] = min(maxmin[i - 1][1], arr[i]);
            
        }
        for(int i = n - 2; i >= 0; i--)
        {
            maxmin[i][2] = max(maxmin[i + 1][2], arr[i]);
            maxmin[i][3] = min(maxmin[i + 1][3], arr[i]);
        }
        
        int ans = INT_MAX;
        ans = min(ans, maxmin[n - k - 1][0] - maxmin[n - k - 1][1]);
        ans = min(ans, maxmin[k][2] - maxmin[k][3]);
        for(int i = 0; i + k < n; i++)
        {
            int minval = maxmin[i][1];
            int maxval = maxmin[i][0];
            if(i + k + 1 < n)
            {
                minval = min(minval, maxmin[i + k + 1][3]);
                maxval = max(maxval, maxmin[i + k + 1][2]);
            }
            int temp = maxval - minval;
            ans = min(ans, temp);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
