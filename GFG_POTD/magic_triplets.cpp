//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	    int n = nums.size(), ans = 0;
	    for(int j = 1; j < n - 1; j++)
	    {
	        int i = 0, k = 0;
	        for(int ind = 0; ind < n; ind++)
	        {
	            if(ind < j && nums[ind] < nums[j])
	                i++;
	            if(ind > j && nums[ind] > nums[j])
	                k++;
	        }
	        ans += i*k;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends