//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
     string secondSmallest(int s, int d){
        
        if(9*d <= s)
          return "-1";
          
          if(s == 9)
          {
              int a = s * ( d + 1 );
              string ans = to_string(a);
              return ans;
          }
        
        
        vector<int>arr(d,0);
        int k = d - 1;
        arr[0] = 1;
        s--;
        
        while(s > 9)
        {
            arr[k] = 9;
            s = s - 9;
            k--;
        }
        
        arr[k] += s;
        
         int end1 = d-1;
         int end2 = d-2;
         int count = 0;
         
         while(count <= 0)
         {
             if(arr[end1]==9 && arr[end2]==9)
             {
                 end1--;
                 end2--;
             }
             else
             {
                 if(arr[end1] == 9)
                 {
                     arr[end1] -= 1;
                     arr[end2] += 1;
                     count++;
                 }
                 else
                 {
                     arr[end1] += 1;
                     arr[end2] -= 1;
                     count++;
                 }
             }
         }
        
        string ans = "";
       
        for(int i = 0; i < arr.size(); i++){
            ans += arr[i] + 48;
        }
       
       return ans;
        
    }
};

//{ driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends