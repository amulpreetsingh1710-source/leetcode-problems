class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        
        for (int i = 0; i < n; i++) {
            // If current index is beyond what we can reach, we're stuck
            if (i > farthest) {
                return false;
            }
            
            // Update the farthest index reachable from position i
            farthest = max(farthest, i + nums[i]);
            
            // Early exit: if we can already reach the end
            if (farthest >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};