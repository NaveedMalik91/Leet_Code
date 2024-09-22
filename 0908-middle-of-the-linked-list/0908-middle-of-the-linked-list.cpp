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
    int getLength(ListNode* head)
    {
        ListNode* curr = head;
        int len = 0;
        while(curr!=NULL)
        {
            len++;
            curr = curr->next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        int length = getLength(head);
        int mid = (length/2)+1;
        ListNode* temp = head;
        while(mid!=1)
        {
            temp = temp->next;
            mid--;
        }
        return temp;
        
    }
};