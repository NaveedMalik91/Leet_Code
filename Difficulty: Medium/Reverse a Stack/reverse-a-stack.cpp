//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    // Optimized helper to insert at bottom
    void insertAtBottom(stack<int> &st, int x) {
        if (st.empty()) {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();
        insertAtBottom(st, x);

        st.push(temp); // Backtrack and push the popped values back
    }

    // Optimized reverse function
    void Reverse(stack<int> &st) {
        if (st.empty()) {
            return;
        }

        int temp = st.top();
        st.pop();
        
        // Recursive call to empty the stack
        Reverse(st);
        
        // Insert elements at the bottom in reverse order
        insertAtBottom(st, temp);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends