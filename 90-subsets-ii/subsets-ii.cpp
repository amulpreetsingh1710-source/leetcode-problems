class Solution {
public:

    void allSubsets(vector<int>& nums,vector<vector<int>>& ans,vector<int>& sub,int i){
        if( i == nums.size()){
            ans.push_back({sub});
            return;
        }
        // include
        sub.push_back(nums[i]);
        allSubsets(nums,ans,sub,i+1);

        // backtracking
        sub.pop_back();

        // exclude
        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx -1]){
            idx++;
        }
        allSubsets(nums,ans,sub,idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> sub;
        vector<vector<int>> ans;
        allSubsets(nums,ans,sub,0);
        return ans;
    }
};