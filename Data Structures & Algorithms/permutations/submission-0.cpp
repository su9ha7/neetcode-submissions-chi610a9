#include <vector>

class Solution {
private:
    void backtrack(std::vector<int>& path, std::vector<bool>& visited, const std::vector<int>& nums, std::vector<std::vector<int>>& result) {
        // Base Case: If the path length equals nums size, we found a complete permutation
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        // Loop through ALL possible elements in nums
        for (int i = 0; i < nums.size(); ++i) {
            // Skip if the element is already used in the current path
            if (visited[i]) {
                continue;
            }

            // Make Choice
            visited[i] = true;
            path.push_back(nums[i]);

            // Recurse
            backtrack(path, visited, nums, result);

            // Undo Choice (Backtrack)
            path.pop_back();
            visited[i] = false;
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        std::vector<bool> visited(nums.size(), false);

        backtrack(path, visited, nums, result);
        return result;
    }
};