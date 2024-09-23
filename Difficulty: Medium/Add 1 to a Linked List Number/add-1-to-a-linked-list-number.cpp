//{ Driver Code Starts
// Initial template for C++

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

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

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

class Solution {
  public:
   Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL) {
            Node* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
   }

    Node* addOne(Node* head) {
       // Reverse the list
       head = reverseList(head);

       // Add one to the reversed list
       Node* temp = head;
       int carry = 1;

       while(temp != NULL) {
           int totalSum = temp->data + carry;
           temp->data = totalSum % 10;
           carry = totalSum / 10;

           // If no carry left, we can break early
           if(carry == 0) break;

           // If it's the last node and carry still exists
           if(temp->next == NULL && carry != 0) {
               temp->next = new Node(carry);
               carry = 0;
           }

           temp = temp->next;
       }

       // Reverse the list again to restore original order
       head = reverseList(head);
       return head;
    }
};


//{ Driver Code Starts.

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
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends