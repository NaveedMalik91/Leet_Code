//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void helper(stack<int>& s, int n,int curr)
    {
        //base case
        if(curr == n/2)
        {
            s.pop();
            return;
        }
        //base case
        if(curr == n/2 + 1)
        {
            s.pop();
            return;
        }
        int top = s.top();
        s.pop();
        helper(s,n,curr+1);
        s.push(top);
    }
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s, int sizeOfStack) {
        if(sizeOfStack == 0)
        {
            return;
        }
        helper(s,sizeOfStack,0);
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++) {
            int x;
            cin >> x;
            myStack.push(x);
        }

        Solution ob;
        ob.deleteMid(myStack, myStack.size());
        while (!myStack.empty()) {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends