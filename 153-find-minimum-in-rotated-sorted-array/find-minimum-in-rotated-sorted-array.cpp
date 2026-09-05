class Solution {
public:

    int findMin(vector<int>& nums) {
        int i = 0,j = nums.size()-1;
        int min_el = INT_MAX;

        while(i<= j){
            int mid = i +(j-i)/2;
            min_el = min(min_el,nums[mid]);
            
            if(nums[mid] >= nums[i] && nums[mid] >= nums[j]){
                i = mid + 1;
            }
            else if( nums[mid] <= nums[i] && nums[mid] <= nums[j]){
                j = mid -1;
            }
            else if (nums[mid] >= nums[i] && nums[mid] <= nums[j]){
                j = mid -1;
            }
            
        }
        return min_el;
    }
};