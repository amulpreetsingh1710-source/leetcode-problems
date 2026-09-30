class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // Find the rightmost node in the left subtree
                TreeNode* prev = curr->left;
                while (prev->right != nullptr) {
                    prev = prev->right;
                }
                
                // Rewire: connect rightmost node to current's right child
                prev->right = curr->right;
                
                // Move the left subtree to the right side
                curr->right = curr->left;
                curr->left = nullptr;
            }
            // Move to the next node on the right path
            curr = curr->right;
        }
    }
};
