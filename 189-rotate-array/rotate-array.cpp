class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        
        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i]; // Place element in rotated position
        }
        
        nums = temp; // Copy temp back to original vector
    }
};
