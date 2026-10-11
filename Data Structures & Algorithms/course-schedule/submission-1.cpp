#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
     
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            
            adj[prereq].push_back(course); 
            inDegree[course]++;            
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int completedCourses = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            completedCourses++;

            
            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;
                
               
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        
        return completedCourses == numCourses;
    }
};
