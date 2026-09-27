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
    vector<double> averageOfLevels(TreeNode* root) {

        vector<double> ans;
        queue<TreeNode*> q;

        if(root == NULL){
            return ans;
        }
        q.push(root);

        while(!q.empty()){
            double size = q.size();
            vector<double> l(size,0.0);

            double sum = 0.0; 
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val; 

                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }

            }

            ans.push_back(sum/size);
        }

        return ans;
    }
};