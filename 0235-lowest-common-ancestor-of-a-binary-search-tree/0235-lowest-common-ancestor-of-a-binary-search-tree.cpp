/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }

        //case1->bothp,q in left
        if(p->val < root->val && q->val < root->val){

            TreeNode* leftans = lowestCommonAncestor(root->left,p,q);
            return leftans;
        }

        //case2->both p,q are in right subtree
        if(p->val > root->val && q->val > root->val){
            TreeNode* rightans = lowestCommonAncestor(root->right,p,q);
            return rightans;
        }
        //case3->p in left and q in right 
        if(p->val < root->val && q->val > root->val){
            
            return root;
        }
        
        //case4-> p in right and q in left 
        if(p->val > root->val && q->val < root->val){
            
            return root;
        }
        return root;
    }
};