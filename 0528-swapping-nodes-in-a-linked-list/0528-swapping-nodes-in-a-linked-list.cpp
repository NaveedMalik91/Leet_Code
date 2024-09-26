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
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int len = getlength(head);
        //case1: 0 or 1 node hai
        if(!head || !head->next)
        {
            return head;
        }
        //right position from start and left position from end of LL 
        
        int lpos = k;
        int rpos = len-k+1;
        if(lpos>rpos)
        {
            swap(lpos,rpos);
        }

        //case2: 
        if(lpos == rpos)
        {
            return head;
        }

        //case3: 
        if(len == 2)
        {
            ListNode* temp_next = head->next;
            temp_next->next = head;
            head->next = NULL;
            head = temp_next;
            return head;

        }

        //case4:
        if(lpos == 1)
        {
            ListNode* left_ptr = NULL;
            ListNode* left_node = head;
            ListNode* right_ptr = head;

            for(int i = 0;i<rpos-2;i++)
            {
                right_ptr = right_ptr->next;
            }
            //right pointer yaha last node se pehle wala node
            ListNode* right_node = right_ptr->next;
            ListNode* right_save = right_node->next;

            //swapping
            right_node->next = left_node->next;
            right_ptr->next = left_node;
            left_node->next = right_save;
            head = right_node;
            return head;


        }

        //case5:
        int bw_Nodes = rpos-lpos-1;
        if(bw_Nodes == 0)
        {
            ListNode* left_ptr = head;
            for(int i = 0;i<lpos-2;i++)
            {
                left_ptr = left_ptr->next;
            }
            //left pointer jaha hai waha se aage ka node
            ListNode* left_node = left_ptr->next;

            
            ListNode* right_ptr = head;
            for(int i = 0;i<rpos-2;i++)
            {
                right_ptr = right_ptr->next;
            }
            //right pointer yaha last node se pehle wala node
            ListNode* right_node = right_ptr->next;

            ListNode* right_save = right_node->next;
            //swapping
            left_ptr->next = right_ptr->next;
            right_node->next = right_ptr;
            right_ptr->next = right_save;
            return head;

        }

        else
        {
            ListNode* left_ptr = head;
            for(int i = 0;i<lpos-2;i++)
            {
                left_ptr = left_ptr->next;
            }
            //left pointer jaha hai waha se aage ka node
            ListNode* left_node = left_ptr->next;

            
            ListNode* right_ptr = head;
            for(int i = 0;i<rpos-2;i++)
            {
                right_ptr = right_ptr->next;
            }
            //right pointer yaha last node se pehle wala node
            ListNode* right_node = right_ptr->next;

            ListNode* right_save = right_node->next;

            //swapping
            left_ptr->next = right_node;
            right_node->next = left_node->next;
            right_ptr->next = left_node;
            left_node->next = right_save;
            return head;


        }


        
    }
};