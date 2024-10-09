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

        //case 1: left aur right me kuch nahi mila
        if(leftans == NULL && rightans==NULL)
        {
            return NULL;
        }
        //case2: left me kuch nhi mila but right mil gya
        else if(leftans == NULL && rightans!=NULL)
        {
            return rightans;
        }
        //case3: left me  mila but right nahi mila
        else if(leftans != NULL && rightans==NULL)
        {
            return leftans;
        }
        //case 4: left aur right dono me mil gya toh jispr khade hai woh return karo
        else
        {
            return root;
        }


        
    }
};