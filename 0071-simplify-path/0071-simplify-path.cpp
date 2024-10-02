class Solution {
public:
    void build_ans(stack<string> &st, string &ans)
    {
        if(st.empty())
        {
            return;
        }
        string top = st.top();
        st.pop();
        build_ans(st,ans);

        //bactrack krte samey popped values ans me store krlo
        ans+=top;
    }
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;
        while(i<path.size())
        {
            //push path of directory in pair i.e /a
            int start = i;
            int end = i+1;
            //next slash aane tk iterate karo
            while(end < path.size() && path[end] != '/')
            {
                end++;
            }
            //next slash aane pe jo directory pair me mili hai 
            //use store karo
            string single_dir = path.substr(start,end-start); //start and its length

            //next iteration single_dir ko shodkar aage se hogi
            i = end;

            //agr single dir aisi hai toh ignore
            if(single_dir == "/" || single_dir == "/.")
            {
                continue;
            }

            //agr /.. nahi hai single_dir me toh stack me single dir daal do
            if(single_dir != "/..")
            {
                st.push(single_dir);
            }
            //nahi toh parent directory oe chale jaao yaani pop() it
            else
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }

        }

        //agr empty hai toh return / else initialise it with emtyp string
        string ans = st.empty()?"/":"";
        build_ans(st,ans);
        return ans;
        
    }
};