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
     long long ans=INT_MIN;
    vector<int> nums;
  public:
    
    long long find(){
        if(nums.size()==1){
            return nums[0];
        }
        long long res=INT_MIN;
        long long sum1=nums[nums.size()-2];
        long long sum2=nums[nums.size()-1];
        res=max(res,sum2);
        res=max(res,sum1-sum2);
        int i=nums.size()-3;
        while(i>=0){
            sum2+=nums[i];
            i--;
            res=max(res,sum2-sum1);
            if(i<0){
                break;
            }
            sum1+=nums[i--];
            res=max(res,sum1-sum2);
        }
        return res;
        
    }
    
    void solve(int src, vector<int> adj[], vector<int> &a){
        nums.push_back(a[src]);
        bool isLeaf=true;
        for(auto x:adj[src]){
            isLeaf=false;
            solve(x,adj,a);
        }
        if(isLeaf){
            ans=max(ans,find());
        }
        nums.pop_back();
    }
    
    long long bestNode(int N, vector<int> &a, vector<int> &p) {
        // code here
        vector<int> adj[N];
        
        for(int i=0;i<N;i++){
            if(p[i]==-1){
                continue;
            }
            adj[p[i]-1].push_back(i);
        }
        solve(0,adj,a);
        return ans;
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
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends