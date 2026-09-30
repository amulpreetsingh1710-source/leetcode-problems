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

    void preorder(TreeNode* root, vector<TreeNode*>& n){
        if(root == NULL){
            return;
        }

        n.push_back(root);
        preorder(root->left,n); 
        preorder(root->right,n);


    }
    
    void flatten(TreeNode* root) {

        if(root == NULL){
            return;
        }
        
        vector<TreeNode*> n;
        preorder(root,n);

        for(int i = 1; i< n.size(); i++){
            root->left = NULL;
            root->right = n[i];
            root = root->right;
        }
        root->left = NULL;
        root->right = NULL;
        return;
    }
};