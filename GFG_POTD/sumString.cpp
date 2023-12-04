//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution{   
public:

    string add_strings(string num1, string num2)
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        
        string output = "";
        
        int carry = 0;
        
        while(i >= 0 or j >= 0 or carry)
        {
            int sum = carry;
            
            if(i >= 0) sum += num1[i--] - '0';
                
            if(j >= 0) sum += num2[j--] - '0';
                
            int rem = sum % 10;
            carry = sum / 10;
            
            output.push_back(rem + '0');
        }
        reverse(output.begin(), output.end());
        return output;
    }
    
    bool check(string str, int start, int n1, int n2, int n)
    {
        string s1 = str.substr(start, n1);
        string s2 = str.substr(start + n1, n2);
        string s3 = add_strings(s1, s2);
        
        int n3 = s3.length();
        
        if(n3 > n - n1 - n2 - start) return false;
        
        if(s3 == str.substr(start + n1 + n2, n3))
        {
            if(start + n1 + n2 + n3 == n) return true;
            
            return check(str, start + n1, n2, n3, n);
        }
        
        return false;
    }
    
    int isSumString(string str){
        //Code here
        
        int n = str.size();
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; i + j < n; j++)
            {
                if(check(str, 0, i, j, n)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.isSumString(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
