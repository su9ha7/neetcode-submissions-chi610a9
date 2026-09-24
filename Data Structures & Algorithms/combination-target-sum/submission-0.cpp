#include <vector>

class Solution {
private:
    void backtrack(int i, int currentSum, int target, std::vector<int>& path, const std::vector<int>& nums, std::vector<std::vector<int>>& result) {
        // Base Case 1: Target matched! Store current path
        if (currentSum == target) {
            result.push_back(path);
            return;
        }

        // Base Case 2: Out of bounds or sum exceeded target
        if (i >= nums.size() || currentSum > target) {
            return;
        }

        // Choice 1: Include nums[i]
        // Note: We pass 'i' (not 'i + 1') because we can reuse the same element
        path.push_back(nums[i]);
        backtrack(i, currentSum + nums[i], target, path, nums, result);

        // Undo choice (Backtrack)
        path.pop_back();

        // Choice 2: Exclude nums[i] and move to the next index
        backtrack(i + 1, currentSum, target, path, nums, result);
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        backtrack(0, 0, target, path, nums, result);
        return result;
    }
};