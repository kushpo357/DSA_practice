//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    // Function to check whether the list is palindrome.
    
    Node* rev(Node* first)
    {
        Node* curr = first;
        Node* prev = NULL;
        
        while(curr != NULL)
        {
            Node* temp = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
    
    bool isPalindrome(Node *head) {
        // Your code here
        
        //for list of size 1
        if(head->next == NULL)
            return true;
            
        //finding last part of first half
        Node* fast = head->next, *slow = head;
        
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            
            fast = fast->next->next;
        }
        
        Node* head2 = slow->next;
        if(fast->next)
        {
            head2 = head2->next;
        }
        
        // reversing the second part
        
        head2 = rev(head2);
        
        // comparing them
        
        int ans = true;
        
        Node* curr1 = head, *curr2 = head2;
        while(curr2 != NULL)
        {
            if(curr1->data != curr2->data)
            {
                ans = false;
                break;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        //returning second to original
        
        head2 = rev(head2);
        
        return ans;
    }
};


//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}

// } Driver Code Ends
