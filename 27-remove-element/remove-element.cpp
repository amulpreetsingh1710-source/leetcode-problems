class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0; // Tracks the position for non-val elements
        
        for (int i = 0; i < nums.size(); i++) {
            // If current element is not the target value
            if (nums[i] != val) {
                nums[index] = nums[i]; // Move it to the front
                index++; // Move the insertion pointer forward
            }
        }
        
        // 'index' represents the count of elements not equal to 'val'
        return index; 
    }
};
