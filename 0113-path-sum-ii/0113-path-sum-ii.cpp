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
    void solve(TreeNode* root, vector<vector<int>> &ans,int targetSum,vector<int>temp,int sum)
    {
        if(root == NULL)
        {
            return;
        }
        sum+=root->val;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            if(sum == targetSum)
            {
                ans.push_back(temp);
            }
            else
            {
                return;
            }

        }

        //recursive call to left and subtree
        solve(root->left,ans,targetSum,temp,sum);
        solve(root->right,ans,targetSum,temp,sum);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root,ans,targetSum,temp,sum);
        return ans;
        
    }
};