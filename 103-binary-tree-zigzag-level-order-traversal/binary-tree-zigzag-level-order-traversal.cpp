class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true; // Tracks the current direction
        
        while (!q.empty()) {
            int size = q.size(); // Number of elements at the current level
            vector<int> currentLevel(size);
            
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                // Determine position based on direction
                int index = leftToRight ? i : (size - 1 - i);
                currentLevel[index] = curr->val;
                
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
            
            ans.push_back(currentLevel);
            leftToRight = !leftToRight; // Flip direction for the next level
        }
        
        return ans;
    }
};
