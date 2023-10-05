//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
  long long int atMostK(string &s, int n, int k)
  {
      vector<int> alpha(26, 0);
      
      long long int start = 0, count = 0, dist = 0;
      
      for(int i = 0; i < n; i++)
      {
          if(!alpha[s[i] - 'a']) dist++;
          
          alpha[s[i] - 'a']++;
          
          while(dist > k)
          {
              alpha[s[start] - 'a']--;
              
              if(!alpha[s[start] - 'a']) dist--;
              
              start++;
          }
          
          if(dist <= k) count = count + i - start + 1;
      }
      
      return count;
  }
  
    long long int substrCount (string s, int k) {
    	//code here.
    	
    	int n = s.size();
    	
    	return (atMostK(s, n, k) - atMostK(s, n, k - 1));
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends
