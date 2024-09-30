class Solution {
public:
    int minSwaps(string s) {
        //agr odd size ki tring hai toh pairs impossible hai
        if(s.size() & 1)
        {
            return -1;
        }
        int count = 0;
        stack<char> st;
        for(auto ch: s)
        {
            if(ch == '[')
            {
                st.push(ch);
            }
            else if(!st.empty()&& st.top() == '[')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }

        //stack me agr kuch brackets hai jinke pairs nahi mile toh unhe balance kar0
        while(!st.empty())
        {
            char a = st.top();
            st.pop();
            char b = st.top();
            st.pop();
            if(a==b)
            {
                count+=1;
            }
            else
            {
                count+=2;
               
            }
            cout<<count;
           
        }
        return count/2;

    }
};