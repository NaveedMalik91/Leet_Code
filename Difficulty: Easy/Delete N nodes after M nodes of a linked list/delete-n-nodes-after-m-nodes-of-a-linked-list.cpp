//{ Driver Code Starts
#include <algorithm>
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
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Class definition with updated method

/* Function to print nodes in a given linked list */
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        if (!head) {
            return head;
        }
        Node* temp = head;
        for (int i = 0; i < m - 1; i++) {
            if (!temp) {
                return head;
            }
            temp = temp->next;
        }

        if (!temp) {
            return head;
        }

        Node* mthNode = temp;
        temp = mthNode->next;
        for (int i = 0; i < n; i++) {
            if (!temp) {
                break;
            }
            Node* temp2 = temp->next;
            delete temp;
            temp = temp2;
        }
        
        mthNode->next = temp; // Fix: Link the m-th node to the next valid node
        linkdelete(temp, n, m);
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

        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }

        int n = arr2[0], m = arr2[1];

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        Node* head = new Node(arr[0]);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        head = ob.linkdelete(head, n, m);
        printList(head);

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}

// } Driver Code Ends