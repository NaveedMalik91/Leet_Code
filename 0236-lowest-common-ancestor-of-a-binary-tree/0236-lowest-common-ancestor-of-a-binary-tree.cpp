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
        if(root == NULL)
        {
            return NULL;
        }

        //agr p aur q root node pe he hai
        if(root->val == p->val)
        {
            return p;
        }
        if(root->val == q->val)
        {
            return q;
        }

        //left ka nas nikaalo mtlb left p yaa q ko dekho kha hai
        TreeNode* leftans = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans = lowestCommonAncestor(root->right,p,q);

        //case 1:
        if(leftans == NULL && rightans==NULL)
        {
            return NULL;
        }
        else if(leftans == NULL && rightans!=NULL)
        {
            return rightans;
        }
        else if(leftans != NULL && rightans==NULL)
        {
            return leftans;
        }
        else
        {
            return root;
        }


        
    }
};