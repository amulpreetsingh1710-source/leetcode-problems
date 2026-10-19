/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(p == root || q == root){
            return root;
        }
        
        if(p->val < root->val && q->val < root->val){ 
            TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
            if(leftLCA){
                return leftLCA;
            }
        }
        else if(p->val > root->val && q->val > root->val){  
            TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);
            if(rightLCA){
                return rightLCA;
            }
        }
        else{
            return root;
        }
        
        return NULL;
        
    }
};