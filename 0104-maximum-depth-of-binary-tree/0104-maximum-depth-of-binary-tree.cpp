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
    int maxDepth(TreeNode* root) {
        TreeNode* temp = root;
        if(temp ==NULL)
        {
            return 0;
        }
        int left_h = maxDepth(temp->left);
        int right_h = maxDepth(temp->right);
        int ans = max(left_h,right_h)+1;
        return ans;
        
    }
};