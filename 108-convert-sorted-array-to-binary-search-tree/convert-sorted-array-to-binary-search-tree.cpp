class Solution {
public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        // Base case: if the bounds cross, there are no elements to process
        if (left > right) {
            return nullptr;
        }
        
        // Always pick the middle element to keep the tree height-balanced
        int mid = left + (right - left) / 2;
        
        // Create the root node with the middle value
        TreeNode* root = new TreeNode(nums[mid]);
        
        // Recursively build the left and right subtrees
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
