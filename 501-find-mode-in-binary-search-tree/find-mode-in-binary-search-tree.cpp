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

    void inorder(TreeNode* root,vector<int>& l){
        if(root == NULL){
            return;
        }

        inorder(root->left,l);
        l.push_back(root->val);
        inorder(root->right,l);

    }
    vector<int> findMode(TreeNode* root) {
        vector<int> l;
        inorder(root,l);

        unordered_map<int,int> m;

        for(int val: l){
            m[val]++;
        }

        int max = INT_MIN;
        for(const auto& it: m){
            if(it.second > max){
                max = it.second;
            }
        }

        vector<int> ans;
        for(const auto& it: m){
            if(it.second == max){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};