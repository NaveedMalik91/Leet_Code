/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* helper(Node* head, unordered_map<Node*, Node*>& mpp) {
        if(head == NULL)
        {
            return NULL;
        }
        Node* newHead = new Node(head->val);
        //map ke andhar old nodes k corrspondong new nodes ki entry daal do
        mpp[head] = newHead;
        //Baki recursion karega
        newHead->next = helper(head->next,mpp); //yaha tk meri new linked list ban gayi
    
        //ab random pointers assign karenge
        //agr kisi node ka random pointer hai toh
        //newhead/node jo banai hai uska b random same he hona chahiye
        //toh purane wali node k corresponding entry jo b hogi use map se lelo
        if(head->random)
        {
            newHead->random = mpp[head->random];
        }

        return newHead;

    }
    Node* copyRandomList(Node* head) {
        // old node se new node ki mapping
        unordered_map<Node*, Node*> mpp;
        Node* ans = helper(head,mpp);
        return ans;

    }
};