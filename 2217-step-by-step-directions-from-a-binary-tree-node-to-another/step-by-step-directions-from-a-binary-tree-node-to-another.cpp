class Solution {
private:
    // Helper function to find the path from the root to the target value
    bool findPath(TreeNode* node, int target, string& path) {
        if (!node) return false;
        if (node->val == target) return true;

        // Try searching the left subtree
        path.push_back('L');
        if (findPath(node->left, target, path)) return true;
        path.pop_back(); // Backtrack if target not found here

        // Try searching the right subtree
        path.push_back('R');
        if (findPath(node->right, target, path)) return true;
        path.pop_back(); // Backtrack if target not found here

        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath = "";
        string destPath = "";

        // Step 1: Find root-to-node paths for both values
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        // Step 2: Skip the common prefix to find the Lowest Common Ancestor (LCA)
        int i = 0;
        int maxLen = min(startPath.length(), destPath.length());
        while (i < maxLen && startPath[i] == destPath[i]) {
            i++;
        }

        // Step 3: Build the final result path
        // Convert all remaining moves from startValue to the LCA into 'U'
        string result(startPath.length() - i, 'U');
        
        // Append the remaining downward moves from the LCA to destValue
        result.append(destPath.substr(i));

        return result;
    }
};
