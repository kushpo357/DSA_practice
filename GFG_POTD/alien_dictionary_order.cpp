//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // Code here
    unordered_map<char, list<char>> createGraph(unordered_map<char, list<char>> &adjList, string dict[], int n) 
    {
        for(int i = 0; i < n - 1; i++) 
        {
            int ptr1 = 0, ptr2 = 0;
            while(ptr1 < dict[i].length() && ptr2 < dict[i + 1].length()) 
            {
                if(dict[i][ptr1] == dict[i + 1][ptr2])
                {
                    ptr1++; ptr2++;
                } else
                {
                    adjList[dict[i][ptr1]].push_back(dict[i + 1][ptr2]);
                    break;
                }
            }
        }
        return adjList;
    }

    bool dfsCycleDetection(char node, unordered_map<char, list<char>> &adjList, unordered_map<char, bool> &visited, unordered_map<char, bool> &recStack)
    {
        visited[node] = true;
        recStack[node] = true;

        for(char neighbor : adjList[node]) 
        {
            if(!visited[neighbor]) 
            {
                if(dfsCycleDetection(neighbor, adjList, visited, recStack))
                    return true;
            } 
            else if(recStack[neighbor])
                return true;
        }

        recStack[node] = false;
        return false;
    }

    bool isCyclic(unordered_map<char, list<char>> &adjList) 
    {
        unordered_map<char, bool> visited;
        unordered_map<char, bool> recStack;

        for(auto &pair : adjList)
        {
            if(!visited[pair.first]) 
            {
                if(dfsCycleDetection(pair.first, adjList, visited, recStack))
                    return true;
            }
        }

        return false;
    }

    void topoSort(char node, unordered_map<char, list<char>> &adjList, unordered_map<char, bool> &visited, string &result)
    {
        visited[node] = true;
        
        for(char neighbor : adjList[node])
        {
            if(!visited[neighbor])
                topoSort(neighbor, adjList, visited, result);
        }

        result = node + result;
    }

    string findOrder(string dict[], int n, int k)
    {
        unordered_map<char, list<char>> adjList;
        createGraph(adjList, dict, n);

        if(isCyclic(adjList)) 
            return "";

        unordered_map<char, bool> visited;
        string result = "";

        for(auto &pair : adjList)
        {
            if(!visited[pair.first])
                topoSort(pair.first, adjList, visited, result);
        }

        return result;
    }
};


//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
