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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* newtail = NULL;

        int sum = 0;
        if(head == NULL)
        {
            return head;
        }
        while(fast!=NULL)
        {
            if(fast->val != 0)
            {
                sum = sum+fast->val;
            }
            else
            {
                slow->val = sum;
                newtail = slow;
                slow = slow->next;
                sum = 0;
            }
            fast = fast->next;
        }
        newtail->next = NULL;
        delete slow;
        return head;
        

        
    }
};