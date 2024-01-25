//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    static bool compare(Item &a, Item &b)
    {
        return ((long long)a.value*b.weight) > ((long long)b.value*a.weight);
    }
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // Your code here
        
        sort(arr, arr + n, compare);
        
        //for(int i = 0; i < n; i++) cout<<arr[i].value<<' '<<arr[i].weight<<endl;
        
        double ans = 0;
        int i = 0;
        while(w && i < n)
        {
            if(w >= arr[i].weight) 
            {
                w -= arr[i].weight;
                ans += arr[i].value;
                i++;
            }
            else
            {
                ans += (double)(w*arr[i].value)/arr[i].weight;
                w = 0;
            }
            //cout<<ans<<endl;
        }
        
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
