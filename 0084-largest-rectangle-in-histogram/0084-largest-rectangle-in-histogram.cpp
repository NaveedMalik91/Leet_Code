class Solution {
public:
    //Yeh hume previous smaller element ke indices dega kisi particular ele ke liye
    vector<int> PSE(vector<int> arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);
        
        for (int i = 0; i < arr.size(); i++) {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
           
            ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    //Yeh hume next smaller element ke indices dega
    vector<int> NSE(vector<int> arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);
        for (int i = arr.size() - 1; i >= 0; i--) {
            int curr = arr[i];
            while (st.top() != -1 &&arr[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    
    int largestRectangleArea(vector<int>& heights) {
        //store next smaller ele indices
        vector<int> next = NSE(heights);
        //agr -1 hai toh sizek baraabar kardo
        for(int i = 0;i<next.size();i++)
        {
            if(next[i] == -1)
            {
                next[i] = next.size();
            }
        }
        //Store prev smaller ele indices
        vector<int> prev = PSE(heights);
        int max_area = INT_MIN;
        for(int i = 0;i<heights.size();i++)
        {
            
            int len = heights[i];
            //prev aur next smaller ele indices ko use krke 
            //formuka tayaar hua
            int width = next[i]-prev[i]-1; 
            int area = len*width;
            max_area = max(max_area,area);
        }
        return max_area;
        
    }
};