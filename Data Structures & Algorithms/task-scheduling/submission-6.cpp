class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>counts;
        for(char task:tasks){
            counts[task]++;
        }
        priority_queue<int>maxheap;
        for(auto pair : counts){
            maxheap.push(pair.second);
        }
        queue<pair<int,int>>q;
        int time =0;
        while(!maxheap.empty()||!q.empty()){
            time++;
            if(!q.empty()&&q.front().second==time){
                maxheap.push(q.front().first);
                q.pop();
            }
            if (!maxheap.empty()) {
                int count = maxheap.top() - 1;
                maxheap.pop();
                if( count>0){
                    q.push({count,time+n+1});
                }
        }
    }
    return time;
    }
};
