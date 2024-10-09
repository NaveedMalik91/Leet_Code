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
    int height(TreeNode* root)
    {
        //base case
        if(root == NULL)
        {
            return 0;
        }
        int left_h = height(root->left);
        int right_h = height(root->right);
        int ans = max(left_h,right_h)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        //base case
        if(root == NULL)
        {
            return true;
        }
        //ek case
        //curr node ki left height nikaalo and right height nikaalo
        //then minus krke dekho  <1 hai agr hai toh true
        int left_h = height(root->left);
        int right_h = height(root->right);
        int diff = abs(left_h - right_h);
        //kya left aur right height ka diff 1 hai
        bool currnode_ans = (diff <= 1);

        //kya left subtree balance hai
        bool left_ans = isBalanced(root->left);
        //kya right subtree balance hai
        bool right_ans = isBalanced(root->right);

        //agr 3 cases hau toh true
        if(currnode_ans && left_ans && right_ans)
        {
            return true;
        }
        else
        {
            return false;
        }
        

        
    }
};