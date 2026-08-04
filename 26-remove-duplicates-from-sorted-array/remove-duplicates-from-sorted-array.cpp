class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int insertIndex = 1; // Start at 1 because the first element is always unique
        
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is different from the previous one, it is unique
            if (nums[i] != nums[i - 1]) {
                nums[insertIndex] = nums[i]; // Move it to the unique section
                insertIndex++; // Move the pointer forward
            }
        }
        
        // 'insertIndex' represents the total number of unique elements
        return insertIndex;
    }
};
