#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            
            adj[prereq].push_back(course); // prereq -> course
            inDegree[course]++;            // Increment padlock count
        }

        // 2. Push all courses with 0 prerequisites into the queue
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order; // Stores our result sequence

        // 3. Process BFS (Kahn's Algorithm)
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            order.push_back(curr); // Add course to our valid sequence

            // Decrement in-degree for all courses dependent on 'curr'
            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;
                
                // If all prerequisites are cleared, push to queue
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // 4. If we processed all courses, return order; otherwise cycle exists -> return []
        if (order.size() == numCourses) {
            return order;
        }
        return {};
    }
};