class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto ch:s)
        {
            if(ch == ']')
            {
                string temp = "";
                //jab tak characters hai toh unhe jodkar string banao
                while(!st.empty() && !isdigit(st.top()[0]))
                {
                    string top = st.top();
                    //opening bracket ko neglect karo
                    temp+=top == "[" ? "" : top;
                    st.pop();
                   
                }

                //digits aaye toh ek final digit banao
                string digit = "";
                while(!st.empty() && isdigit(st.top()[0]))
                {
                    digit+=st.top();
                    st.pop();
                }
                reverse(digit.begin(),digit.end());
                int n = stoi(digit);




                //part by part string ko decode karo
                string curr_dec = "";
                while(n--)
                {
                    curr_dec += temp;
                }

                st.push(curr_dec); //final string for a part e.g. 3[ab] = ababab
            }

           
            //sab char ko string me convert karke stack me daal diya
            else
            {
                string temp(1,ch);
                //cout<<temp;
                st.push(temp);
            }
        }

        //last me jo strings decoded hai unhe pop krke reverse krdo aur return
        string ans;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};