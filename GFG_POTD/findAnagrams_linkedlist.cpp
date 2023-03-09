//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution
{
    public:
    
    vector<Node*> findAnagrams(struct Node* head, string s)
    {
        vector<Node*> res;
        vector<int> v(26, 0);
        
        for(int i=0; i<s.size(); i++)
            v[s[i] -'a'] += 1;
            
        int n = s.size();
        Node* a = head;
        Node* b = head;
        Node* d = head;
        
        while(b != NULL)
        {
            vector<int> t(26, 0);
            int i = 0;
            
            while(i < n && b != NULL)
            {
                t[b->data - 'a'] += 1;
                i += 1;
                d = b;
                b = b->next;
            }
            
            while(v != t && b != NULL)
            {
                t[a->data -'a'] -= 1;
                a = a->next;
                d = b;
                t[b->data -'a'] += 1;
                b = b->next;
            }
            
            if(v == t)
            {
                d->next = NULL;
                
                res.push_back(a);
                a = b;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends