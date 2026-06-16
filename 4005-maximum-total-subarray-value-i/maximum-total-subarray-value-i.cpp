class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int g = nums[0],s = nums[0];
        for(int val : nums){
            if (val >= g ){
                g = val;
            }
            if(val < s){
                s = val;
            }
        }
        return (long long)(g-s)*k;
        
    }
};