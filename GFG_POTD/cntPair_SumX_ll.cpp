//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void append(struct Node** headRef, struct Node** tailRef, int newData) {
    struct Node* new_node = new Node(newData);

    if (*headRef == NULL) {
        *headRef = new_node;
    }

    else {
        (*tailRef)->next = new_node;
    }
    *tailRef = new_node;
}

void printList(struct Node* head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        
        vector<int> l1, l2;
        
        int ans = 0;
        
        Node* curr = head1;
        
        while(curr != NULL)
        {
            l1.push_back(curr->data);
            curr = curr->next;
        }
        
        curr = head2;
        
        while(curr != NULL)
        {
            l2.push_back(curr->data);
            curr = curr->next;
        }
        
        sort(l1.begin(), l1.end());
        sort(l2.begin(), l2.end());
        
        int n1 = l1.size();
        int n2 = l2.size();
        
        for(int i = 0, j = n2 - 1; i < n1 && j >= 0;)
        {
            int temp = l1[i] + l2[j];
            if(temp == x)
            {
                i++;
                j--;
                ans++;
            }
            else if(temp > x) j--;
            else i++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        struct Node* head1 = NULL;
        struct Node* tail1 = NULL;
        struct Node* tail2 = NULL;
        struct Node* head2 = NULL;
        int n1, n2, tmp, x;
        cin >> n1;
        while (n1--) {
            cin >> tmp;
            append(&head1, &tail1, tmp);
        }
        cin >> n2;
        while (n2--) {
            cin >> tmp;
            append(&head2, &tail2, tmp);
        }
        cin >> x;
        Solution obj;
        cout << obj.countPairs(head1, head2, x) << '\n';
    }
    return 0;
}
// } Driver Code Ends
