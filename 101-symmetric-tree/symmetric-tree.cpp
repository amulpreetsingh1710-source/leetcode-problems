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
    bool helper(TreeNode* p, TreeNode* q){
        if(p == NULL || q == NULL){
            return p == q;
        }

        bool far_symm = helper(p->left, q->right);
        bool near_symm = helper(p->right, q->left);

        return far_symm && near_symm && p->val == q->val;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return helper(root->left, root->right);
    }
};