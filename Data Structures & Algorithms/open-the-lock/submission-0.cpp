#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

class Solution {
public:
    int openLock(std::vector<std::string>& deadends, std::string target) {
        std::unordered_set<std::string> visited(deadends.begin(), deadends.end());

        // Edge case: "0000" is a deadend
        if (visited.count("0000")) return -1;
        // Edge case: target is already "0000"
        if (target == "0000") return 0;

        std::queue<std::string> q;
        q.push("0000");
        visited.insert("0000"); // Mark starting state as visited

        int turns = 0;

        while (!q.empty()) {
            int qSize = q.size(); // Number of combinations at current turn level

            for (int i = 0; i < qSize; ++i) {
                std::string curr = q.front();
                q.pop();

                if (curr == target) return turns;

                // Generate all 8 possible next combinations
                for (int wheel = 0; wheel < 4; ++wheel) {
                    for (int diff : {-1, 1}) {
                        std::string nextState = curr;
                        // Wrap around math for '0' - '9'
                        nextState[wheel] = (curr[wheel] - '0' + diff + 10) % 10 + '0';

                        if (!visited.count(nextState)) {
                            visited.insert(nextState);
                            q.push(nextState);
                        }
                    }
                }
            }
            turns++; // Increment turn count after exhausting current BFS layer
        }

        return -1; // Target unreachable
    }
};