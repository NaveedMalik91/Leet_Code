/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> LL;
        // insert val into vector
        while(head)
        {
            LL.push_back(head->val);
            head = head->next;
        }

        //Stack to hold index of values
        stack<int> st;
        vector<int> ans(LL.size()); //init 0
        for(int i = 0;i<LL.size();i++)
        {
            //agr koi element(jiska index hai stack me) 
            //LL(vector) k element se bada hai toh woh
            //woh LL wala elemnt next greater hoga
            //us stack wale element se
            while(!st.empty()&& LL[i] > LL[st.top()])
            {
                int index = st.top();
                st.pop();
                ans[index] = LL[i];
            }
            //agr shota hai toh uska index stack me daal do
            st.push(i);
        }
        return ans;
    }
};