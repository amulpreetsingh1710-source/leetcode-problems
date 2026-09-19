class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = nums[0];
        int l = 0, r =0;
        int min_len = INT_MAX;

        while(r< nums.size()){
            if(sum >= target){
                min_len = min(min_len, r-l+1);
                sum -= nums[l];
                l++;
            }
            else{
                r++;
                if(r < nums.size()){
                    sum += nums[r];
                }
                
            }
        }

        return min_len == INT_MAX ? 0 : min_len;
    }
};