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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> st; // Using a vector as a stack for easy access
        
        for (int num : nums) {
            TreeNode* curr = new TreeNode(num);
            
            // 1. Pop all smaller nodes; the last popped node becomes curr's left child
            while (!st.empty() && st.top()->val < num) {
                curr->left = st.top();
                st.pop();
            }
            
            // 2. If there is a larger node left in the stack, curr becomes its right child
            if (!st.empty()) {
                st.top()->right = curr;
            }
            
            // Push current node onto the stack
            st.push(curr);
        }
        
        // The bottom-most element of the stack (first element) will be the global maximum/root
        // Keep popping until you reach the bottom-most element
        TreeNode* root = nullptr;
            while (!st.empty()) {
                root = st.top();
                st.pop();
            }
        return root;

    }
};
