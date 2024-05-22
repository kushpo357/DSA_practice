//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    bool isValid(vector<int>& stations, int K, double distance, int n){
        int new_stations = 0;
        for(int i=1; i<n; i++)
            new_stations += floor((stations[i] - stations[i-1]) / distance);
            
        return new_stations <= K;
    }
  public:
    double findSmallestMaxDist(vector<int> &stations, int K){
        int n = stations.size();
        double start = 0;
        double end = stations[n-1] - stations[0];
        while(end - start > 1e-6){
            double mid = start+(end-start)/2.0;
            if(isValid(stations, K, mid, n))
                end = mid;
            else
                start = mid;
        }
        
        return start + 0.000001;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends
