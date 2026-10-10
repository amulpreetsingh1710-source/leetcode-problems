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
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == NULL){
            return true;
        }
        else if(max != NULL && root->val >= max->val){
            return false;
        }
        else if(min != NULL && root->val <= min->val){
            return false;
        }

        bool leftSubtree = helper(root->left,min, root); // when ever we go left side of tree we set the max val which is curr root val i.e. Nodes in the left must be shorter than that max value.
        bool rightSubtree = helper(root->right,root, max); // when ever we go right side of tree we set the min val which is curr root val i.e. Nodes in the right must be larger than that min value. 

        return leftSubtree && rightSubtree;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* min = NULL;
        TreeNode* max = NULL;
        return helper(root, min , max);
    }       
};