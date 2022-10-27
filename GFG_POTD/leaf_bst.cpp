//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int arr[],int N) {
        // code here
        vector<int> v,st;
        st.push_back(arr[0]);
        int temp;
        for(int i = 1; i < N; i++)
        {
            if(arr[i] < st.back())
                st.push_back(arr[i]);
            else
            {
                int count = 0;
                temp = st.back();
                while(arr[i] > st.back() && !st.empty())
                {
                    st.pop_back();
                    count++;
                }
                st.push_back(arr[i]);
                if(count > 1)
                    v.push_back(temp);
            }
        }
        v.push_back(st.back());
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends