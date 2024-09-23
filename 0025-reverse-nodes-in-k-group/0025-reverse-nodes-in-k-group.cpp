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
    int getlength(ListNode* head)
    {
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* curr_next = NULL;
        if(head == NULL || k == 1)
        {
            return head;
        }
        if(head->next == NULL)
        {
            return head;
        }
        int pos = 0;

        //kya k-elements hai b ki nahi
        int len = getlength(head);
        if(len < k)
        {
            return head;
        }
        while(curr !=NULL && pos<k)
        {
            curr_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr_next;
            pos++;
        }
        ListNode* ans = NULL;
        if(curr_next !=NULL)
        {
            ans = reverseKGroup(curr_next,k);
            //last me link kardo
            head->next = ans;
           
        }
        return prev;

        
    }
};