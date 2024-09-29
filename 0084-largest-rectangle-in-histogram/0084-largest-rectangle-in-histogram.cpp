class Solution {
public:
    vector<int> PSE(vector<int> arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);
        // left to right jaa rahe hai hai
        // aur curr se piche wale ele compare kr rahe hai
        for (int i = 0; i < arr.size(); i++) {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            // smaller element mil gaya
            ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    vector<int> NSE(vector<int> arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);
        for (int i = arr.size() - 1; i >= 0; i--) {
            int curr = arr[i];
            while (st.top() != -1 &&arr[st.top()] >= curr) {
                st.pop();
            }
            // smaller element mil gaya
            ans[i] = st.top();
            // curr ele ko stack me daale
            // woh b kisi ele ka smaller ho sakta hai
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = NSE(heights);
        for(int i = 0;i<next.size();i++)
        {
            if(next[i] == -1)
            {
                next[i] = next.size();
            }
        }
        vector<int> prev = PSE(heights);
        int max_area = INT_MIN;
        for(int i = 0;i<heights.size();i++)
        {
            
            int len = heights[i];
            int width = next[i]-prev[i]-1; //formula
            int area = len*width;
            max_area = max(max_area,area);
        }
        return max_area;
        
    }
};