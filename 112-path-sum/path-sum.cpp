class Solution {
public:
    bool helper(TreeNode* root, int targetSum, int pathSum) {
        // Base case: Leaf node check
        if (root->left == nullptr && root->right == nullptr) {
            return (pathSum + root->val == targetSum);
        }

        bool leftFound = false;
        bool rightFound = false;

        // Traverse left subtree
        if (root->left) {
            leftFound = helper(root->left, targetSum, pathSum + root->val);
        }

        // Traverse right subtree (Only if left didn't already find it)
        if (root->right && !leftFound) {
            rightFound = helper(root->right, targetSum, pathSum + root->val);
        }
        
        return leftFound || rightFound;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        return helper(root, targetSum, 0);
    }
};
