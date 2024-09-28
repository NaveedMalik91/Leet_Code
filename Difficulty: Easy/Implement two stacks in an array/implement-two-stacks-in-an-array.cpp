//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks {
public:
    int * arr;
    int top1;
    int top2;
    int n;

    // Constructor
    twoStacks(int size = 100) {
        arr = new int[size]; // Allocate an array of given size
        this->n = size;
        top1 = -1;           // Initialize top1 for stack1
        top2 = size;         // Initialize top2 for stack2 (points to one past the last element)
    }

    // Function to push an integer into stack1.
    void push1(int x) {
        if (top2 - top1 <= 1) { // Check for stack overflow
            return; // Overflow condition
        }
        top1++; // Increment top1
        arr[top1] = x; // Insert element
    }

    // Function to push an integer into stack2.
    void push2(int x) {
        if (top2 - top1 <= 1) { // Check for stack overflow
            return; // Overflow condition
        }
        top2--; // Decrement top2
        arr[top2] = x; // Insert element
    }

    // Function to remove an element from top of stack1.
    int pop1() {
        if (top1 == -1) { // Check for underflow
            return -1; // Indicate underflow
        }
        return arr[top1--]; // Return and decrement top1
    }

    // Function to remove an element from top of stack2.
    int pop2() {
        if (top2 == n) { // Check for underflow
            return -1; // Indicate underflow
        }
        return arr[top2++]; // Return and increment top2
    }

    // Destructor to free allocated memory
    ~twoStacks() {
        delete[] arr; // Free allocated memory
    }
};



//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--) {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1) {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            } else if (QueryType == 2) {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends