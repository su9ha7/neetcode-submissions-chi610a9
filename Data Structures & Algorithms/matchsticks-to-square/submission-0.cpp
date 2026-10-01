#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    bool backtrack(int index, const std::vector<int>& matchsticks, std::vector<int>& sides, int target) {
        // Base Case: All matchsticks placed successfully
        if (index == matchsticks.size()) {
            return sides[0] == target && sides[1] == target &&
                   sides[2] == target && sides[3] == target;
        }

        // Try placing matchsticks[index] into each of the 4 sides
        for (int j = 0; j < 4; ++j) {
            // Check if placing this matchstick exceeds the target side length
            if (sides[j] + matchsticks[index] > target) {
                continue;
            }

            // Pruning: Skip trying identical side sums to avoid redundant branches
            bool alreadyTried = false;
            for (int k = 0; k < j; ++k) {
                if (sides[k] == sides[j]) {
                    alreadyTried = true;
                    break;
                }
            }
            if (alreadyTried) {
                continue;
            }

            // Choice
            sides[j] += matchsticks[index];

            // Explore next matchstick
            if (backtrack(index + 1, matchsticks, sides, target)) {
                return true;
            }

            // Backtrack (undo choice)
            sides[j] -= matchsticks[index];
        }

        return false;
    }

public:
    bool makesquare(std::vector<int>& matchsticks) {
        if (matchsticks.size() < 4) {
            return false;
        }

        int sum = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) {
            return false;
        }

        int target = sum / 4;

        // Optimization: Sort in descending order to fail fast on invalid branches
        std::sort(matchsticks.rbegin(), matchsticks.rend());

        // Early check: single matchstick longer than target length
        if (matchsticks[0] > target) {
            return false;
        }

        std::vector<int> sides(4, 0);
        return backtrack(0, matchsticks, sides, target);
    }
};