class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(auto ch:s)
        {
            //pehla char push kardo
            if(st.empty())
            {
                st.push(ch);
            }
            //agr match hai tph pop krdo
            else if(!st.empty() && st.top() == ch)
            {
                st.pop();
            }
            //nahi toh push kardo agr match nahi hai
            else
            {
                st.push(ch);
            }
        }

        //bina pair waale char hoge
        string str;
        while(!st.empty())
        {
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    
       
        
    }
};