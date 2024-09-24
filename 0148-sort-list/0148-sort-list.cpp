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
        ListNode* fast = head->next;
        while(fast && fast->next)
        {
           slow = slow->next;
           fast = fast->next->next;
           
        }
        return slow;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* list1 = head1;
        ListNode* list2 = head2;
        
        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;
        if(list1 == NULL)
        {
        return list2;
        }
        if(list2 == NULL)
        {
        return list1;
        }

        while(list1!=NULL && list2!=NULL)
        {
           
            if(list1->val <= list2->val)
            {
                mptr->next = list1;
                mptr = list1;
                list1 = list1->next;
            }
            else
            {
                mptr->next = list2;
                mptr = list2;
                list2 = list2->next;
               
               
            }

        }
        if(list1!=NULL )
        {
            mptr->next = list1;
            // temp = list1;
            // list1 = list1->next;
        }
        if(list2!=NULL )
        {
            mptr->next = list2;
            // temp = list2;
            // list1 = list1->next;
        }
        return ans->next;
        
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* mid = getMiddle(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        left = sortList(left);
        right = sortList(right);
        ListNode* ans = merge(left,right);
        return ans;
    }
};