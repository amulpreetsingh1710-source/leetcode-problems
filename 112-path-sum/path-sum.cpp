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
    void helper(TreeNode* root, int pathSum, vector<int>& allPathsSum){
        if(root->left == NULL && root->right == NULL){
            allPathsSum.push_back(pathSum + root->val);
            return;
        }

        if(root->left){
            helper(root->left,pathSum + root->val, allPathsSum);
        }

        if(root->right){
            helper(root->right,pathSum + root->val, allPathsSum);
        }

        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> allPathsSum;
        
        if(root == NULL){
            return false;
        }

        helper(root,0, allPathsSum);

        for(int pathSum : allPathsSum){
            if(pathSum == targetSum){
                return true;
            }
        }

        return false;
    }

};