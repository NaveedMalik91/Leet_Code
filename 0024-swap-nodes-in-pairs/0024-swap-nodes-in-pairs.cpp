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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* second_next = second->next;
        ListNode* Rec_ans = NULL;

       
        
        Rec_ans = swapPairs(second_next);
        second->next = first;
        first->next = Rec_ans;
        

        


        return second;
    }
};