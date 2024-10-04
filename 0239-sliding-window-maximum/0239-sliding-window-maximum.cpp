class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        //process first window
        for(int i = 0; i< k;i++)
        {
            //first in window
            int element  = nums[i];
            //agr queue me curr ele chota hai toh use nikaal do
            while(!dq.empty() && element > nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        //process remaining window
        //k index tk 1 elemnt add hoga k aage wal
        // aur prevoius window ke elements deque se remove honge agr 
        //curr window mw lie nahi krte
        for(int i = k; i < nums.size();i++)
        {
            //ans store karo jo peli window ka largest hai
            ans.push_back(nums[dq.front()]);

            //removal
            if(!dq.empty() && i - dq.front() >= k)
            {
                dq.pop_front();
            }

            //pop chote elements
            int element  = nums[i];
            //agr queue me curr ele chota hai toh use nikaal do
            while(!dq.empty() && element > nums[dq.back()])
            {
                dq.pop_back();
            }

            //addition
            dq.push_back(i);
        
        }
        //last window
        ans.push_back(nums[dq.front()]);
        return ans;
        
    }
};