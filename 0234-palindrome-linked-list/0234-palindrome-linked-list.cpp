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
    ListNode* getMiddle(ListNode* head) {
        // code here
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL) {
            fast = fast->next;
            if (fast->next != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        head = prev;
        return head;
    }
    bool compare_LL(ListNode* head1,ListNode* head2)
    {
        //Should use temporary pointers 
        while(head1!=NULL && head2 != NULL)
        {
            if(head1->val != head2->val)
            {
                return false;
            }
            else
            {
                head1 = head1->next;
                head2 = head2->next;
            }
            

        }
        return true;

    }
    bool isPalindrome(ListNode* head) {
        // break into two halves
        ListNode* MidNode = getMiddle(head);
        ListNode* head2 = MidNode->next;
        MidNode->next = NULL;
        // reverse second half
        head2 = reverseList(head2);
        // compare
        bool ans = compare_LL(head,head2);
        return ans;
    }
};