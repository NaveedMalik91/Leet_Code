class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        //Approach:- Next greate element
        //days = warmer_day(Next greater) minus st.top();

        //stack to store index of days
        stack<int> st;
        vector<int> ans(temp.size(),0);
        for(int i = 0;i<temp.size();i++){
            //agr curr day temp greater hai than the day jo st.top
            //pe hai toh us din se curr day tk length nikalo
            while(!st.empty() && temp[i] > temp[st.top()])
            {
                //st.top shows particular day jiske liye next warmer temp nikaal rahe hai
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
        
    }
};