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
    int ans = 0;
public:
    void pathfinder(TreeNode* root, long long target){
        if(!root){
            return;
        }
        //Base Case
        if(target == root->val){
            ++ans;
        }

        //call left recursively
        pathfinder(root->left,target-root->val);
        pathfinder(root->right,target-root->val);
    }
    int pathSum(TreeNode* root, long long targetSum) {
        if(root){
            pathfinder(root,targetSum);
            //call recursively to left and right node
            //and afterwards consider it as root
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        
        return ans;
        
    }
};