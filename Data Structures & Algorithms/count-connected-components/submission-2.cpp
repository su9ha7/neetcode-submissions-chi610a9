class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(const auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool>visited(n,false);
        int componentcount =0;

        for ( int i =0 ; i<n ; i++){
            if (!visited[i]){
                componentcount++;

                queue<int>q;
                q.push(i);
                visited[i]=true;

                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    for( int neighbour : adj[curr]){
                        if(!visited[neighbour]){
                            visited[neighbour]=true;
                            q.push(neighbour);
                        }
                    }
                }
            }
        }
         return componentcount++;
    }
};
