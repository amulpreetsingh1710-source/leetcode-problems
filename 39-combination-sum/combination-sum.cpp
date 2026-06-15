class Solution {
public:
    set<vector<int>> s;
    void helper(vector<int>& arr,int i, int target, vector<int>& combin, vector<vector<int>>& ans){

        if(target < 0 || i == arr.size()){
            return;
        }
        if(target == 0){
            //store
            if(s.find(combin) == s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
            
            return;
        }

        // include
        combin.push_back(arr[i]);
        helper(arr,i+1,target-arr[i],combin,ans);  //single
        helper(arr,i,target-arr[i],combin,ans);    // multiple times


        combin.pop_back();           // backtracking
        //exclusion
        helper(arr,i+1,target,combin,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> combin;
        vector<vector<int>> ans;
        helper(arr,0,target,combin,ans);
        return ans;
    }
};