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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        //agr length ke baraabar hai k toh
        //linked list reverse hoke waapis actual linked list banegi
        ListNode* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }
        if(k==length)
        {
            return head;
        }

        temp->next = head;  // Make it circular
        k = k % length;
        int StepsTonewHead = length-k;
        ListNode* Newtail = head;
        for(int i = 1; i<StepsTonewHead;i++)
        {
            Newtail = Newtail->next;
        }
        ListNode* newHead = Newtail->next;
        Newtail->next = NULL;
        return newHead;
    }
};