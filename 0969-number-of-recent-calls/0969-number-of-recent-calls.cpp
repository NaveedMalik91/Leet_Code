class RecentCounter {
public:
queue<int> q;
    RecentCounter() {
        
    }
    
    
    int ping(int t) {
        //push cur request
        q.push(t);

        //pop the request from queue older than curr
        while(!q.empty() && q.front() < (t-3000))
        {
            q.pop();
        }

        //recent calls: R = [t-3000 ,t]
        return q.size();

        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */