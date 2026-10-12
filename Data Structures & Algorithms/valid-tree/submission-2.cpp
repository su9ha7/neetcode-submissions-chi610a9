class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if( edges.size() != n-1) return false;

        vector<vector<int>> adj(n);
        for(const auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        visited.insert(0);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for( int neighbour : adj[curr]){
                if(!visited.count(neighbour)){
                    visited.insert(neighbour);
                    q.push(neighbour);
                }
            }
        }
        return visited.size() == n;

    }
};
