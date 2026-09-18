class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        int currentpassengers=0;
        for(const auto&trip:trips){
            int numpassengers = trip[0];
            int startloc = trip[1];
            int endloc = trip[2];
            while(!minheap.empty()&& minheap.top().first<=startloc){
                currentpassengers -= minheap.top().second;
                minheap.pop();
            }
            currentpassengers +=numpassengers;
            if(currentpassengers>capacity){
                return false;
            }
            minheap.push({endloc,numpassengers});
        }
        return true ;
    }
};