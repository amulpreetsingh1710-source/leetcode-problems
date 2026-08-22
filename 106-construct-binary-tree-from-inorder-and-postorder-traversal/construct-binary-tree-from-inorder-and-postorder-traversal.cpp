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
    int search(vector<int>& inorder,int l,int r,int val){
        for(int i = l; i<= r; i++){
            if(inorder[i] == val){
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int l,int r,int &postIdx){
        if(l > r){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postIdx]);

        int idx = search(inorder, l, r, postorder[postIdx]);
        postIdx--;

        root->right = helper(inorder,postorder,idx+1,r,postIdx);
        root->left = helper(inorder,postorder,l,idx-1,postIdx);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size()-1;
        return helper(inorder,postorder,0,inorder.size()-1,postIdx);
    }
};