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
    void solve(TreeNode* root, vector<int> &v,int level)
    {
        int size = v.size();
        if(root == NULL)
        {
            return;
        }
        if(level == size)
        {
            v.push_back(root->val);
        }
        solve(root->right,v,level+1);
        solve(root->left,v,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root == NULL)
        {
            return v;
        }
        int level = 0;
        solve(root,v,level);
        return v;
        
    }
};