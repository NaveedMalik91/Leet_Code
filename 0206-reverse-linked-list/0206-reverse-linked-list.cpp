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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
            

        }
        head = prev;
        return head;

       //for recursive-> return reverseusingRec(curr,prev); 
    }

    /* Recursive Solution*/
    ListNode* reverseusingRec(ListNode* curr, ListNode* prev) {
        if(curr == NULL)
        {
            return prev;
        }
        ListNode* curr_next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = curr_next;
        ListNode* reverse_ans = reverseusingRec(curr,prev);
        return reverse_ans;

    }

    

};