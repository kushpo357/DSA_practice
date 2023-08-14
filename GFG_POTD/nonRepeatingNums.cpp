//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        
        vector<int> v(2, 0);
        int n = nums.size();
        
        for(int i = 0; i < n; i++) v[0] ^= nums[i];
        
        int setbit = 0;
        
        while(v[0])
        {
            v[0] = v[0] >> 1;
            setbit++;
        }
        
        setbit = (1<<--setbit);
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] & setbit) v[1] ^= nums[i];
            else v[0] ^= nums[i];
        }
        
        return v;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
