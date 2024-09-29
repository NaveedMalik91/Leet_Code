class MinStack {
public:
    vector<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        //agr empty hai mtlb pehla ele insert kr rahe hai
        if(st.empty())
        {
            pair<int,int> p;
            //curr value
            p.first = val;
            //curr min
            p.second = val;
            st.push_back(p);
        }
        else
        {
            pair<int,int> p;
            p.first = val;
            //curr min vector ke andhar last me pair ka second wala element hoga
            int prev_min = st.back().second;
            p.second = min(prev_min,p.first);
            //pair ko vector ke andhar;
            st.push_back(p);

        }
    }
    
    void pop() {
        //simply pop_back()
        st.pop_back();
        
    }
    
    int top() {
        return st.back().first;
        
    }
    
    int getMin() {
        return st.back().second;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */