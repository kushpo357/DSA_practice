// Homework
// 1207 -  Unique Number of Occurrences - Leetcode
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        int n = arr.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[arr[i]]++;
        
        set<int> s;
        for(auto it : mp)
        {
            if(s.find(it.second) != s.end())
                return false;
            
            s.insert(it.second);
        }
        return true;
    }
};
