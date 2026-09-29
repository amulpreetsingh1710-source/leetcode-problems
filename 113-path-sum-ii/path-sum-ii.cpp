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

    void helper(TreeNode* root, int targetSum, int pathSum, vector<int>& l, vector<vector<int>>& ans){
        if(root->left == NULL && root->right == NULL){
            l.push_back(root->val);
            if(pathSum + root->val == targetSum){
                ans.push_back(l);
            }
            l.pop_back();
            return;
        }

        l.push_back(root->val);

        if(root->left){    
            helper(root->left, targetSum, pathSum + root->val, l, ans);
        }
        if(root->right){  
            helper(root->right, targetSum, pathSum + root->val, l, ans);
        }

        if(!l.empty()){
            l.pop_back();
        }
        
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> l;
        if(root == NULL){
            return ans;
        }
        helper(root, targetSum, 0, l, ans);

        return ans;
    }
};