class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans = 0;
        for(auto ch:s)
        {
            //opening bracket 
            // valid paranthesis bn sakti hai
            if(ch == '(')
            {
                st.push(ch);
                ans++;
            }
            //closing bracket
            else
            {   //stack me opening bracket hai toh
            //match found ans dec and pop the top
                if(!st.empty() && st.top() == '(')
                {
                    st.pop();
                    ans--;
                }

                //agr closing bracket hai aur
                //match nahi mila mtlb closing he hai
                //ans++
                else
                {
                    ans++;
                }
            }
        }
        return ans;
        
    }
};