//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    int steppingNumbers(int n, int m)
    {
        // Code Here
        int ans = 0;
        queue<int> que;
        if(n == 0)
            ans++;
        for(int i = 1; i < 10; i++)
        {
            que.push(i);
            if(i >= n)
            {
                if(i > m)
                    return ans;
                else
                    ans++;
            }
        }
        while(!que.empty())
        {
            int num = que.front();
            que.pop();
            int num1;
            if(num%10)
            {
                num1 = (num*10) + (num%10) - 1;
                que.push(num1);
                if(num1 >= n && num1 <= m)
                    ans++;
            }
            int num2;
            if(num%10 != 9)
            {
                num2 = (num*10) + (num%10) + 1;
                que.push(num2);
                if(num2 >= n && num2 <= m)
                    ans++;
            }
            if(num1 > m || num2 > m)
                return ans;
        }
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends