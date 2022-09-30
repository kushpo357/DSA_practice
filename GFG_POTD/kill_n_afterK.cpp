//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int safePos(int n, int k) {
        // code here
        struct Node* last;
        
        for(int i = 1; i <= n ; i++){
            
            if(i == 1){
                last = AddToEmpty(last, i);
                continue;
            }
            
            last = add(last, i);
        }
        
        for(int j = 1; j < n; j++)
            last = TravDelete(last, k);
            
        return last->data;
    }
    
    struct Node{
        
        int data;
        struct Node* next;
        
    };
    
    struct Node* AddToEmpty(struct Node* last, int d){
        
        struct Node* temp = new Node;
        temp->data = d;
        last = temp;
        last->next = temp;
        
        return last;
    }
    
    struct Node* add(struct Node* last, int d){
        
        struct Node* temp = new Node;
        temp->data = d;
        temp->next = last->next;
        last->next = temp;
        
        return temp;
    }
    
    struct Node *TravDelete(struct Node* last, int k){
        
        struct Node* temp;
        
        for (int i = 1; i < k; i++){
            last = last->next;
            
        }
        temp = last->next;
        
        last->next = last->next->next;
        
        delete(temp);
        
        return last;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends