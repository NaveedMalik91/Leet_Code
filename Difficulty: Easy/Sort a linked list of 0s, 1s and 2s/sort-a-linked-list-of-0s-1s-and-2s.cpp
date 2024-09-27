//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends
/*

  Node is defined as
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
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
            /*if (!head || !(head->next))
                return head;
            Node *temp = head;
            int cnt1 = 0;
            int cnt2 = 0;
            int cnt3 = 0;
            while(temp!=NULL)
            {
                if(temp->data == 0)
                {
                    cnt1++;
                }
                else if(temp->data == 1)
                {
                    cnt2++;
                }
                else{
                    cnt3++;
                }
                temp = temp->next;
            }
            temp = head;
            while(temp!=NULL && cnt1 !=0)
            {
                temp->data = 0;
                temp = temp->next;
                cnt1--;
            }
             while(temp!=NULL && cnt2 !=0)
            {
                temp->data = 1;
                temp = temp->next;
                cnt2--;
            }
             while(temp!=NULL && cnt3 !=0)
            {
                temp->data = 2;
                temp = temp->next;
                cnt3--;
            }
            return head;
        }*/
        
        
        //Approach2
        Node* zeroes = new Node(0);
        Node* ones = new Node(0);
        Node* twos = new Node(0);
        
        Node* zero_head = zeroes;
        Node* ones_head = ones;
        Node* twos_head = twos;
        
        Node* temp = head;
        while(temp!=NULL)
        {
            if(temp->data == 0)
            {
                zero_head->next = temp;
                zero_head = zero_head->next;
            }
            else if(temp->data == 1)
            {
                ones_head->next = temp;
                ones_head = ones_head->next;
            }
            else
            {
                twos_head->next = temp;
                twos_head = twos_head->next;
            }
            temp = temp->next;
        }
        //agr 1 yaa 1 wali list exist karti hai toh usw link karo 0 wali k saath
        if(ones->next!=NULL)
        {
            zero_head->next = ones->next;
            ones_head->next = twos->next;
        }
        //nahi toh 0 aur 2 wali jod do
        else
        {
            zero_head->next = twos->next;
        }
        
        //1 aur 2 wali jod do
        ones_head->next = twos->next;
        twos_head->next = NULL;
        head = zeroes->next;
        return head;
    }
    
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends