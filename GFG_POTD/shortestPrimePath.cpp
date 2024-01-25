class Solution{   
    public:
    bool flag=0;
    vector<int> sieve;
    
    //prime sieve
    void prime_sieve()
    {
        sieve.resize(10000,1);
        int n=10000;
        sieve[0]=0;
        sieve[1]=0;
        
        for(int i=2;i*i<=n;i++)
        {
            if(sieve[i])
            {
                for(int j=i*i;j<=n;j+=i)
                sieve[j]=0;
            }
        }
        
        flag=1;
        
    }
    
    //function to check , number is prime or not
    bool is_prime(string s)
    {
        int num=stoi(s);
        return bool(sieve[num]);
    }
    
    //helper function
    int help(string& s1,string& s2)
    {
        if(s1==s2)
        return 0;
        
        unordered_set<string> vis;;
        queue<string> q;
        q.push(s1);
        vis.insert(s1);
        int res=0;
        
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                string curr=q.front();
                q.pop();
                
                if(curr==s2)
                return res;                                                                      
                
                string temp=curr;
                for(int i=0;i<4;i++)
                {
                    temp=curr;
                    for(char ch='0';ch<='9';ch++)
                    {
                        if(i==0 and ch=='0')
                        continue;
                    
                        temp[i]=ch;
                        if(is_prime(temp) and vis.find(temp)==vis.end())
                        {
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
    
    int solve(int Num1,int Num2)
    {   
      if(!flag)
      prime_sieve();
      
      string s1=to_string(Num1);
      string s2=to_string(Num2);
      
      int ans=help(s1,s2);
      return ans;
    }
};
