class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;

public:
    MyQueue() {
        
    }

    /* TOOK O(N) and O(N) space and time complexity
    
    // Push element x to the back of queue
    void push(int x) {
        // Move all elements from st1 to st2
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        
        // Push the new element into st1
        st1.push(x);
        
        // Move elements back from st2 to st1
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    // Removes the element from the front of queue and returns that element
    int pop() {
        int frontElement = st1.top();
        st1.pop();
        return frontElement;
    }
    
    // Get the front element
    int peek() {
        return st1.top();
    }
    
    // Returns whether the queue is empty
    bool empty() {
        return st1.empty();
    }

    */

    //Approach2 :- O(1) and O(N) push and pop resp.

    void push(int x) {
        st1.push(x);
        
    }
    
    // Removes the element from the front of queue and returns that element
    int pop() {
        if(!st2.empty())
        {
            int top = st2.top();
            st2.pop();
            return top;
        }
        else
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            int top = st2.top();
            st2.pop();
            return top;
        }
        return -1;
    }
    
    int peek() {
        if(!st2.empty())
        {
            return st2.top();
        }
        else
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();;
        }
        return -1;
    }
    
    // Returns whether the queue is empty
    bool empty() {
        if(st1.empty())
        {
            while(!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
            return st1.empty();
        }
        else
        {
            return st1.empty();
        }
    }



};
