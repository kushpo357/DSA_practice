//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    
    static double transform(int x)
    {
        return log2((double)x)/(double)x;
    }
    static bool compare( int o1, int o2)
    {
        return (transform(o1)<transform(o2));
    }
    long long countPairs(vector<int> arr, vector<int> brr)
    {
       //Your code here
       
       long long ans = 0;
       int n = brr.size(), m = arr.size();
       sort(arr.begin(), arr.end(), compare);
       sort(brr.begin(), brr.end(), compare);
      
        
    for(int i = 0, j = 0; i < m; i++)
    { 
        while(j < n && transform(arr[i]) > transform(brr[j]))
        {
            j++;
        }
        ans += j;
    }      
              
    return ans; 
       
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends
