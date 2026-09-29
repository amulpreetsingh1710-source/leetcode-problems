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

    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int left_ht = minDepth(root->left);
        int right_ht = minDepth(root->right);

        return (left_ht == 0 || right_ht == 0) ? max(left_ht,right_ht) + 1 : min(left_ht, right_ht) + 1 ;
    }
};