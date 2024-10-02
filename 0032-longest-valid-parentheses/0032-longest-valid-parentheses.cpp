class Solution {
public:
    int longestValidParentheses(string s) {
        int len = 0;
        int max_len = 0;
        //stack to store the indices of paranthesis
        stack<int> st;
        st.push(-1);
        for(int i = 0;i<s.length();i++)
        {
            char ch = s[i];
            if(ch == '(')
            {
                st.push(i);
            }
            //agr closing bracket hai
            else
            {
                //agr closing bracket hai toh pop kro(invalid pranthesis)
                st.pop();
                //agr stack empty hai
                if(st.empty())
                {
                    st.push(i);
                }
                //agr empty nahi hai
                //aur closing bracket mil gayi
                else
                {
                   
                    //curr index i.e closing bracket ka index aur st.top yaani
                    // opening ka index minus kr do
                    int len = i-st.top();
                    max_len = max(max_len,len);
                }
            }
        }
        return max_len;
        
    }
};