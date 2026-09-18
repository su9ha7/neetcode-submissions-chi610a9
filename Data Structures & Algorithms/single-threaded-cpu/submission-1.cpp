class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>>sortedTasks(n);
        for(int i=0;i<n;i++){
            sortedTasks[i]={tasks[i][0],tasks[i][1],i};
        }
        sort(sortedTasks.begin(),sortedTasks.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<int>result;
    long long currentTime =0;
    int taskIdx = 0;
    while(taskIdx < n || !minHeap.empty()) {
        if(minHeap.empty() && currentTime<sortedTasks[taskIdx][0]){
            currentTime = sortedTasks[taskIdx][0];
        }
        while(taskIdx<n && sortedTasks[taskIdx][0]<=currentTime){
            minHeap.push({sortedTasks[taskIdx][1],sortedTasks[taskIdx][2]});
            taskIdx++;
        }
        auto [procTime,origIdx] = minHeap.top();
        minHeap.pop();
        currentTime += procTime;
        result.push_back(origIdx);
    }
    return result;
}
};