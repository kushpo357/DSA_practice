//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    
    int precompute(vector<int> &v, int num)
    {
        if(!v[num] || v[num] == 1) return v[num];
        if(v[num] == -2) return 0;
        
        int sqrsum = 0;
        int temp = num;
        while(temp)
        {
            sqrsum += (temp%10)*(temp%10);
            temp /= 10;
        }
        
        if(sqrsum == 1)
        {
            v[num] = 1;
            return 1;
        }
        v[num] = -2;
        v[num] = precompute(v, sqrsum);
        
        return v[num];
    }
    int nextHappy(int n){
        // code here
        vector<int> v(325, -1);
        for(int i = 1; i < 325; i++)
        {
            precompute(v, i);
        }
        v[0] = 0;
        int sqrsum = 0;
        while(!v[sqrsum])
        {   
            n++;
            sqrsum = 0;
            int temp = n;
            while(temp)
            {
                sqrsum += (temp%10)*(temp%10);
                temp /= 10;
            }
        }
        return n;
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
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends