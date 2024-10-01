class Solution {
public:
    bool isValid(string s) {
        //string 'a' se start he nahi ho rahi toh false
        if(s[0] == 'b' || s[1] == 'c')
        {
            return false;
        }

        stack<char> st;
        for(auto ch:s)
        {
            if(ch == 'a')
            {
                st.push(ch);
            }
            else if(ch == 'b')
            {
                //agr stack me hai toh b ko daalo
                if(!st.empty() && st.top() == 'a')
                {
                    st.push(ch);
                }
                //ab ke wajaaye ba aa gya toh pair nahi ban payega
                else
                {
                    return false;
                }

                   
            }
            else
            {
                //ab hai aur c b mil gaya toh pop krdo b ko
                if(!st.empty()&& st.top() == 'b')
                {
                    st.pop();
                    //b ko pop krne k baad agr stack me a hai toh woh b pop krdo
                    if(!st.empty() && st.top() == 'a')
                    {
                        st.pop();
                    }
                    //top pe 'b' aur 'c' toh mila but a nahi mila
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    //muje a mila but b aur c nahi mila
                    return false;
                }

                
            }
        }
        if(!st.empty())
        {
            return false;
        }
        return true;
        
        
         
    }
};