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
    void solve(ListNode* head,int &carry)
    {
        if(!head)
        {
            return;
        }

        //hum pehle hi last me chale jayege aur phir last se return karte aayge
        solve(head->next,carry);

        int digit = head->val * 2+carry;
        head->val = digit%10;
        carry = digit/10;

    }
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        solve(head,carry);
        //agr carry rehta hai toh head me insert kr do
        if(carry!=0)
        {
            ListNode* carryNode = new ListNode(carry);
            carryNode->next = head;
            head = carryNode;
        }
        return head;
    
       
    }
};