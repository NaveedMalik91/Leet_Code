

 //Using morris traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr){
            //left is not then visit it goto right
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            //left is not null establish links with successors
            else{
                TreeNode* pred = curr->left;
                //Find inorder predecessor
                //ek baar left then go rightmost
                while(pred->right != curr && pred->right){
                    pred = pred->right;
                }
                // Right child is null so link establish karo root k sath
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                //right child is not null aur left already visited hai so remove link and moveright
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }

            }
        }
        return ans;
       
        
    }
    
};