//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // Write your code here.
        if(!n) return 1;
        
        if(m == 1)
        {
            if(!seats[0]) n--;
            if(n) return 0;
            else return 1;
        }
        
        if(!seats[0] && !seats[1])
        {
            n--;
            seats[0] = 1;
        }
        
        for(int i = 1; i < m - 1; i++)
        {
            if(!n) break;
            if(seats[i - 1] || seats[i] || seats[i + 1]) continue;
            n--;
            seats[i] = 1;
        }
        
        if(!seats[m - 2] && !seats[m - 1] && n) n--;
        
        if(n) return 0;
        return 1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends