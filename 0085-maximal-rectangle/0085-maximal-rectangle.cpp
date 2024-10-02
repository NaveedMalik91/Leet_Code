class Solution {
public:
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

    // Yeh hume next smaller element ke indices dega
    vector<int> NSE(vector<int> arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);
        for (int i = arr.size() - 1; i >= 0; i--) {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        // store next smaller ele indices
        vector<int> next = NSE(heights);
        // agr -1 hai toh size k baraabar kardo
        for (int i = 0; i < next.size(); i++) {
            if (next[i] == -1) {
                next[i] = next.size();
            }
        }
        // Store prev smaller ele indices
        vector<int> prev = PSE(heights);
        int max_area = INT_MIN;
        for (int i = 0; i < heights.size(); i++) {

            int len = heights[i];
            // prev aur next smaller ele indices ko use krke
            // formuka tayaar hua
            int width = next[i] - prev[i] - 1;
            int area = len * width;
            max_area = max(max_area, area);
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        //convert char vector to int
        vector<vector<int>>v;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0;i<n;i++)
        {
            vector<int> row;
            for(int j = 0;j<m;j++)
            {
                row.push_back(matrix[i][j]-'0');

            }
            //insert single interger row into v
            v.push_back(row);
        }

        //pehli row ka area nikalkar store kr lo
        int area = largestRectangleArea(v[0]);

        //next row pe jaao aur value ko add karo row 1 and row2
        //aur new raow banao
        for(int i = 1;i<n;i++)
        {
            
            for(int j = 0;j<m;j++)
            {
               if(v[i][j]!=0)
               {
                    //new row will be formed by adding its values with previous row values
                    v[i][j] += v[i-1][j];
               }
               //agr kisi row ki value zero hai toh use add mt kar0
               //zero he rehne do kyuki histogram agr0 se start hua hai
               //toh uske baad add nahi karna hai
               else
               {
                    v[i][j]=0;
               }
            }

            //jo nayi row bani uska area nikalo aur dono ka max store karo
            area = max(area,largestRectangleArea(v[i]));
            
            
        }
        return area;

    }
};