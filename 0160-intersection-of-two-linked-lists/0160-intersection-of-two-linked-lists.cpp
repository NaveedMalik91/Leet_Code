/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* head1 = headA;
        ListNode* head2 = headB;
        while(head1->next && head2->next)
        {
            if(head1 == head2)
            {
                return head1;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        //koi ek linked list agr NULL hogai
        //agr list1 NULL pajunch gayi

        //agr linked list2 choti hai toh
        if(head1->next == NULL)
        {
            //is case me list1 ki length kitni zayada hai
            int len = 0;
            while(head2->next)
            {
                len++;
                head2 = head2->next;
            }
            //head ko waapis start pe le jao
            head2 = headB;
            //jitni length zayada hai utne se initialize karo
            while(len--)
            {
                headB = headB->next;
            }
        }


         //agr linked list1 choti hai
        else
        {
            //is case me list2 ki length kitni zayada hai
            int len = 0;
            while(head1->next)
            {
                len++;
                head1 = head1->next;
            }

            //jitni length zayada hai utne se initialize karo
            while(len--)
            {
                headA = headA->next;
            }
        }

        while(headA!=headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
        
    }
};