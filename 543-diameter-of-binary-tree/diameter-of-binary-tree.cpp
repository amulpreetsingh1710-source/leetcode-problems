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
    int heightAndDiameter(TreeNode* root,int &maxdiameter){
        if(root == NULL){
            return 0;
        }

        int left_ht = heightAndDiameter(root->left,maxdiameter);
        int right_ht = heightAndDiameter(root->right,maxdiameter);

        maxdiameter = max((left_ht + right_ht),maxdiameter);

        return max(left_ht,right_ht) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int maxdiameter = 0;
        heightAndDiameter(root,maxdiameter);

        return maxdiameter;
        
    }
};