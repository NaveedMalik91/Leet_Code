/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxdepth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftDepth = maxdepth(root->left);
        int rightDepth = maxdepth(root->right);
        int ans = max(leftDepth,rightDepth)+1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = maxdepth(root->left)+maxdepth(root->right);
        int op4 = max(op1,max(op2,op3));
        return op4;
        
    }
};