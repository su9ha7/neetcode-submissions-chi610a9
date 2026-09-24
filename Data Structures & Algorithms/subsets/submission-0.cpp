#include <vector>

class Solution {
private:
    void backtrack(int i, std::vector<int>& path, const std::vector<int>& nums, std::vector<std::vector<int>>& result) {
        // Base case: processed all elements, store the subset built so far
        if (i == nums.size()) {
            result.push_back(path);
            return;
        }

        // Choice 1: Include nums[i]
        path.push_back(nums[i]);
        backtrack(i + 1, path, nums, result);

        // Undo choice (Backtrack)
        path.pop_back();

        // Choice 2: Exclude nums[i]
        backtrack(i + 1, path, nums, result);
    }

public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> path; // Stores the current subset being built
        backtrack(0, path, nums, result);
        return result;
    }
};