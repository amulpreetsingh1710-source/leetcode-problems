class Solution {
public:

    void storeSubsets(vector<int>& arr,vector<vector<int>>& ans,vector<int>& sub,int i){
        if(i == arr.size()){
            ans.push_back({sub});
            return;
        }
        

        //include
        sub.push_back(arr[i]);
        storeSubsets(arr,ans,sub,i+1);
        //backtrack
        sub.pop_back();
        
        // exclude
        storeSubsets(arr,ans,sub,i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> ans;
        storeSubsets(nums,ans,sub,0);
        return ans;
    }
};