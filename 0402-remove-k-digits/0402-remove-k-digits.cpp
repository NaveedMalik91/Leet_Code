class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        stack<char> st;
        for(auto digit : num)
        {
            if(k>0)
            {
                while(!st.empty() && st.top() > digit)
                {
                    st.pop();
                    k--;
                    if(k == 0)
                    {
                        break;
                    }
                }
            }
            //push rest elements
            st.push(digit);
        }
        //k elements abhi remove nahi huye 
        if(k > 0)
        {
            while(!st.empty() && k)
            {
                st.pop();
                k--;
            }
        }

        //build ans
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        //remove trailing zeroes
        while(ans.size() > 0 && ans.back() == '0')
        {
            ans.pop_back();
        }
        //reverse ans
        reverse(ans.begin(),ans.end());
        return ans == "" ? "0" : ans;
    }
};