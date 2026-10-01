#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    bool backtrack(int index, const std::vector<int>& nums, std::vector<int>& subsets, int target) {
        // Base Case: All numbers placed into a valid subset
        if (index == nums.size()) {
            return true;
        }

        // Try placing nums[index] into each of the k subsets
        for (int j = 0; j < subsets.size(); ++j) {
            // Check if adding nums[index] exceeds target sum
            if (subsets[j] + nums[index] > target) {
                continue;
            }

            // Choice
            subsets[j] += nums[index];

            // Recurse to next number
            if (backtrack(index + 1, nums, subsets, target)) {
                return true;
            }

            // Undo Choice (Backtrack)
            subsets[j] -= nums[index];

            // Pruning: If this subset becomes empty after backtracking,
            // trying other empty subsets will produce identical results.
            if (subsets[j] == 0) {
                break;
            }
        }

        return false;
    }

public:
    bool canPartitionKSubsets(std::vector<int>& nums, int k) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        // Early Check 1: Must divide evenly
        if (sum % k != 0) {
            return false;
        }

        int target = sum / k;

        // Sort descending to optimize search space
        std::sort(nums.rbegin(), nums.rend());

        // Early Check 2: Largest element exceeds target
        if (nums[0] > target) {
            return false;
        }

        std::vector<int> subsets(k, 0);
        return backtrack(0, nums, subsets, target);
    }
};