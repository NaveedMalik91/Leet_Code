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
    int getPos(vector<int> inorder, int ele)
    {
        for(int i = 0; i< inorder.size();i++)
        {
            if(inorder[i] == ele)
            {
                return i;
            }
        }
        return -1;

    }

    //pass pre_index by reference 
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int in_start,int &pre_idx,int in_end)
    {
        
        int size = preorder.size();

        //out of bound
        if(pre_idx >= size || in_start > in_end)
        {
            return NULL;
        }

        //1-case solve
        //get root i.e element of preorder traversal
        int ele = preorder[pre_idx];
        pre_idx++;

        //create node for this ele
        TreeNode* root  = new  TreeNode(ele);

        //search position of this ele in inorder traversal
        int pos = getPos(inorder,ele);

        //node ke left me 
        //left part me curr_ele se pehle waale elements lagege i.e pos-1
        root->left = solve(preorder, inorder,in_start,pre_idx,pos-1);
        root->right = solve(preorder, inorder,pos+1,pre_idx,in_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int in_start = 0;
        int pre_start = 0;
        int in_end = inorder.size();
        TreeNode* ans = solve(preorder,inorder,in_start,pre_start,in_end);
        return ans;
        

    }
};