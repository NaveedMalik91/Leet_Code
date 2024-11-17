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
    int D = 0;
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftDepth = height(root->left);
        int rightDepth = height(root->right);
        int currD = leftDepth+rightDepth;
        D = max(D,currD);
        return max(leftDepth,rightDepth)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        height(root);
        return D;
       
        
    }
};