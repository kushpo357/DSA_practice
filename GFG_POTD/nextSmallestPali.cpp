//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

    void plusone(int num[], int n)
    {
        for(int i = (n - 1) / 2; i >= 0; i--)
        {
            if(num[i] == 9) num[i] = 0;
            else 
            {
                num[i]++;
                //cout<<num[i]<<"meow"<<i<<endl;
                break;
            }
        }
    }
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	    int i;
	    for(i = (n - 1)/2 ; i >= 0; i--)
	    {
	        //cout<<num[i]<<' '<<num[n - 1 - i]<<endl;
	        if(num[i] == num[n - 1 - i]) continue;
	        if(num[i] < num[n - 1 - i])
	        {
	            //cout<<"bhau"<<endl;
	            plusone(num, n);
	        }
	        break;
	    }
	    
	    vector<int> v(n, 0);
	    if(i < 0)
	    {
	        plusone(num, n);
	        if(!num[0])
	        {
	            v.push_back(0);
	            v[0] = v[n] = 1;
	            return v;
	        }
	    }
	    for(int i = (n - 1)/ 2; i >= 0; i--) v[i] = v[n - 1 - i] = num[i];
	    
	    return v;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
