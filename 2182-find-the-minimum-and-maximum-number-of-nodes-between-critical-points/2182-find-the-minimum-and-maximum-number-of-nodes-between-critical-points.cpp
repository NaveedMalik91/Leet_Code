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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans{-1,-1};
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* curr_nxt = curr->next;

        //agr 3 nodes nahi hue toh -1,-1 return krdo
        if(curr==NULL)
        {
            return ans;
        }
        if(prev==NULL)
        {
            return ans;
        }
        if(curr_nxt==NULL)
        {
            return ans;
        }

        //initial positions of nodes/critical points
        int CP1 = -1;
        int CP2 = -1;
        int i = 1;
        int min_dis = INT_MAX;
        while(curr_nxt!=NULL)
        {
            bool isCP;
            if(curr->val > prev->val && curr->val > curr_nxt->val||(curr->val < prev->val && curr->val < curr_nxt->val))
            {
                isCP = true;
            }
            else
            {
                isCP = false;
            }
           //agr koi critical point milta hai toh fist and last CP current  i(pos) se assign kardo
            if(isCP && CP1 == -1)
            {
                CP1 = i;
                CP2 = i;
            }

            //agr uske baad koi CP milta hai toh use CP2 kahenge aur uska 
            //min distance nikalege uss CP K saath jo usse pehle sabse hoga
            //most recent
            else if(isCP)
            {
                min_dis = min(min_dis,i-CP2);
                CP2 = i;

            }

            ++i;
            prev = prev->next;
            curr = curr->next;
            curr_nxt = curr_nxt->next;

        }

        //ek he CP hoga toh phir b -1,-1
        if(CP1 == CP2)
        {
            return ans;
        }
        else
        {
            ans[0] = min_dis;
            ans[1] = CP2-CP1;
        }
        return ans;


         

        
    }
};