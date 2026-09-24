#include <vector>

class Solution {
private:
    void backtrack(int start, int n, int k, std::vector<int>& path, std::vector<std::vector<int>>& result) {
        // Base Case: If the path length reaches k, we found a valid combination
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        // Loop through choices starting from 'start' up to n
        // Optimization: stop early if there aren't enough remaining numbers to fill k elements
        for (int i = start; i <= n - (k - path.size()) + 1; ++i) {
            // Make Choice
            path.push_back(i);

            // Recurse to next number (i + 1 ensures elements are strictly increasing / unique)
            backtrack(i + 1, n, k, path, result);

            // Undo Choice (Backtrack)
            path.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        backtrack(1, n, k, path, result);
        return result;
    }
};