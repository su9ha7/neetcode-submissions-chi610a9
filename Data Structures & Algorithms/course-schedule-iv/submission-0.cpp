#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // 1. Initialize a 2D boolean grid: isPrereq[u][v] = true if u is a prereq of v
        vector<vector<bool>> isPrereq(numCourses, vector<bool>(numCourses, false));

        // 2. Fill in direct prerequisites
        for (const auto& pre : prerequisites) {
            int u = pre[0];
            int v = pre[1];
            isPrereq[u][v] = true; // Direct edge u -> v
        }

        // 3. Floyd-Warshall algorithm to compute indirect prerequisites
        // k is the intermediate course
        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    // If i is a prereq of k AND k is a prereq of j, then i is a prereq of j
                    if (isPrereq[i][k] && isPrereq[k][j]) {
                        isPrereq[i][j] = true;
                    }
                }
            }
        }

        // 4. Answer each query in O(1) time
        vector<bool> ans;
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            ans.push_back(isPrereq[u][v]);
        }

        return ans;
    }
};