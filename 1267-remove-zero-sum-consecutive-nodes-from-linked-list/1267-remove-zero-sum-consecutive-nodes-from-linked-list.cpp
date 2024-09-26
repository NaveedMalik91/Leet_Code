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
    ListNode* helper(ListNode* head) {
        if (!head)
        {
            return NULL;
        }
        if (!head->next) // Handle single node case
        {
            if(head->val == 0)
            {
                return nullptr;
            }
            else
            {
                return head;
            }
        }
       
        ListNode* temp = head;
        ListNode* headNode = head;  // Initially, keep the head as headNode
        int sum = 0;
        while (temp != NULL) {
            sum += temp->val;
            if (sum == 0) {
                headNode = temp->next;  // Update headNode when sum becomes zero
            }
            temp = temp->next;
        }
        // agr kuch nodes milke zero bna diye hai aur head ab change 

        if (headNode != head) {  
            return helper(headNode);  // Recur for the new headNode
        } else {
            head->next = helper(head->next);  // Recur for the next nodes
            return head;
        }
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        return helper(head);
    }
};
