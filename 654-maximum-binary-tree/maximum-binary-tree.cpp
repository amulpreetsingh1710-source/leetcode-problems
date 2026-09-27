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

    int maximum(vector<int>& nums, int l, int r){
        int maxIdx = -1;
        int g = INT_MIN;

        for(int i = l; i <= r; i++){
            if(nums[i] > g){
                maxIdx = i;
                g = nums[i];
            }
        }
        return maxIdx;
    }

    TreeNode* helper(vector<int>& nums, int l, int r){

        if(l > r){
            return NULL;
        }

        int maxIdx = maximum(nums, l, r);

        TreeNode* root = new TreeNode(nums[maxIdx]);

        root->left = helper(nums, l, maxIdx-1);
        root->right = helper(nums, maxIdx+1, r);

        return root;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        return helper(nums, 0, nums.size()-1);
    }
};