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
    bool hasCycle(ListNode *head) {
        map<ListNode*,bool> table;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            //kya table ke andhar node pada hua hai
            if(table[temp] == false)
            {
                //agr nahi toh daal do
                table[temp] = true;
            }
            //agr pda hua hai toh mtlb cycle hai
            else
            {
                return true;
            }
            temp = temp->next;
            
        }
        return false;
        
    }
};