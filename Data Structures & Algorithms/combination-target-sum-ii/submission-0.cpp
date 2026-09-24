#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(int start, int currentSum, int target, std::vector<int>& path, const std::vector<int>& nums, std::vector<std::vector<int>>& result) {
        // Base Case 1: Target matched
        if (currentSum == target) {
            result.push_back(path);
            return;
        }

        // Loop through candidate elements starting from 'start'
        for (int i = start; i < nums.size(); ++i) {
            // Pruning: if adding nums[i] exceeds target, stop (since array is sorted)
            if (currentSum + nums[i] > target) {
                break;
            }

            // Skip duplicates at the current decision level
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            // Make Choice
            path.push_back(nums[i]);

            // Recurse to next index (i + 1 ensures elements are used at most once)
            backtrack(i + 1, currentSum + nums[i], target, path, nums, result);

            // Undo Choice (Backtrack)
            path.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;

        // Sorting is required to handle duplicates and allow early pruning
        std::sort(nums.begin(), nums.end());

        backtrack(0, 0, target, path, nums, result);
        return result;
    }
};