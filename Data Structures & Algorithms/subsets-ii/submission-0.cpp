#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(int start, std::vector<int>& path, const std::vector<int>& nums, std::vector<std::vector<int>>& result) {
        // Every combination/path along the recursion tree is a valid subset
        result.push_back(path);

        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicates: if the current element is identical to the previous one
            // at the same decision depth, skip it to prevent duplicate subsets
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            // Choice
            path.push_back(nums[i]);

            // Explore (move to next index)
            backtrack(i + 1, path, nums, result);

            // Backtrack (undo choice)
            path.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;

        // Step 1: Sort to bring duplicates together
        std::sort(nums.begin(), nums.end());

        backtrack(0, path, nums, result);
        return result;
    }
};
