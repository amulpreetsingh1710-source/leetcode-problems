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
    int helper(TreeNode* root, TreeNode* minRange, TreeNode* maxRange,int minDis){

        if(root == NULL){
            return minDis;
        }
        if(maxRange != NULL){
            minDis = min(minDis, maxRange->val - root->val);
        }
        if(minRange != NULL){
            minDis = min(minDis, root->val - minRange->val);
        }
        

        int minLeft = helper(root->left, minRange, root, minDis);
        int minRight = helper(root->right, root, maxRange, minDis);

        return min(minLeft,minRight);
    }
    int minDiffInBST(TreeNode* root) {
        int minDis = INT_MAX;

        return helper(root, NULL, NULL, minDis);
    }
};