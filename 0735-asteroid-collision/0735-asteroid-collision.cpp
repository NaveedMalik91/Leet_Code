class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) { 
        stack<int> st;
        for(auto val : asteroids)
        {
            bool destroy = false;
            //
            //+ve
            if(val > 0)
            {
                st.push(val);
            }
            
            //-ve value
            else
            {
                //stack empty hai yaa val negative hai
                if(st.empty() || st.top() < 0)
                {
                    st.push(val);
                }
                //val negative hai aur top pe positive hai
                else if(st.top() > 0)
                {
                    // collision
                    //jb tk positive rahega aur empty na ho collision krte raho
                    while(!st.empty() && st.top()>0)
                    {
                        if(abs(val) == st.top())
                        {
                            destroy = true;
                            st.pop();
                            //asteroid khatam toh break
                            break;
                        }
                        //top ki value shoti hai
                        //pop top value
                        // new val  stack me push tabhi karge
                        //agr woh kisi b value se destro nahi hui
                        else if(abs(val) > st.top())
                        {
                            st.pop();
                            

                        }
                        //new value shoti hai toh collision hogi but top ki value 
                        // wahi rahegi aur collison ruk jayegi
                        else
                        {
                            destroy = true;
                            break;
                        }
                    }

                    //koi new value agr destroy nahi hui
                    //toh use push kardo
                    if(!destroy)
                    {
                        st.push(val);
                    }

                }
            }
        }  
        //reverse
        vector<int> ans(st.size());
        for(int i = st.size()-1;i>=0;i--)
        {
            ans[i] = st.top();
            st.pop();
        }
        return ans;

        
    }
};