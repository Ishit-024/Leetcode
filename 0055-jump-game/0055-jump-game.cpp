class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > maxReach) {
                return false; // If we cannot reach this position
            }
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) {
                return true; // We can reach the end
            }
        }
        return false; // If we finish the loop without being able to reach the end
    }
};
