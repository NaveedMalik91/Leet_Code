class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1; // Start with the first list
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* ptr1_prev = NULL;
        int carry = 0;

        // Traverse while either list is not exhausted
        while (ptr1 != NULL && ptr2 != NULL) {
            int sum = ptr1->val + ptr2->val + carry;
            ptr1->val = sum % 10; // Update the value at ptr1
            carry = sum / 10;     // Update carry
            ptr1_prev = ptr1;     // Save the last node of l1
            ptr1 = ptr1->next;    // Move to the next node in l1
            ptr2 = ptr2->next;    // Move to the next node in l2
        }

        // Handle remaining nodes in l1
        while (ptr1 != NULL) {
            int sum = ptr1->val + carry;
            ptr1->val = sum % 10;
            carry = sum / 10;
            ptr1_prev = ptr1;
            ptr1 = ptr1->next;
        }

        // Handle remaining nodes in l2
        while (ptr2 != NULL) {
            // Create a new node in l1 for the l2's remaining node
            int sum = ptr2->val + carry;
            if (ptr1_prev) {
                ptr1_prev->next = new ListNode(
                    sum % 10); // Create a new node if there's a carry
                ptr1_prev = ptr1_prev->next;
            } else {
                head = new ListNode(sum % 10); // If l1 was empty
                ptr1_prev = head;
            }
            carry = sum / 10;
            ptr2 = ptr2->next; // Move to the next node in l2
        }

        // If carry is left at the end
        if (carry != 0) {
            ptr1_prev->next = new ListNode(carry);
        }

        return head;
    }
};
