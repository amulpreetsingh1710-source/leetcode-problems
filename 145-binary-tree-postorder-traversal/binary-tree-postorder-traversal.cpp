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

    void helper(vector<int> &ans,TreeNode* root){
        TreeNode* curr = root;

        if(curr == NULL){
            return;
        }

        helper(ans,curr->left);
        helper(ans,curr->right);
        ans.push_back(curr->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(ans,root);

        return ans;
    }
};