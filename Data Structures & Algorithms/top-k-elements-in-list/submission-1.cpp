class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int>count;
        for( int n :nums){
            count[n]++;
        }
        vector<pair<int,int>>freqlist;
        for( auto x:count){
            freqlist.push_back({x.second,x.first});
        }
        sort(freqlist.rbegin(),freqlist.rend());
        vector<int>result;
        for(int i=0;i<k;i++){
            result.push_back(freqlist[i].second);
        }
        return result;

        
    }
};
