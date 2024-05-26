//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    
    int findMinCost(string x, string y, int cx, int cy) {
        int n=x.size(),m=y.size();
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int i=1;i<=m;i++){
            prev[i]=cy*i;
        }
        
        for(int i=0;i<n;i++){
            curr[0]=((i+1)*cx);
            for(int j=0;j<m;j++){
                if(x[i]==y[j]){
                    curr[j+1]=prev[j];
                }
                else{
                    curr[j+1]=min(cx+prev[j+1],cy+curr[j]);
                }
            }
            prev=curr;
        }
        return prev[m]; 
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
