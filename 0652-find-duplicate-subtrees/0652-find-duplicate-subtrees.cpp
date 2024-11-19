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
    vector<TreeNode*>ans;
    unordered_map<string,int> subtreemap;
    string preorder(TreeNode* root){
        if(!root){
            return "N";
        }
        string curr = to_string(root->val);
        string left = preorder(root->left);
        string right = preorder(root->right);
        string s = curr+","+left+","+right;
        if(subtreemap.find(s) != subtreemap.end()){
            if(subtreemap[s] == 1){
                ans.push_back(root);
            }
            subtreemap[s]++;
        }
        else{
            subtreemap[s] = 1;
        }
        return s;

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preorder(root);
        return ans;
    }
};