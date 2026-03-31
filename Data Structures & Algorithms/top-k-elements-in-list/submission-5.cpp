class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int>count;
        for( int n :nums){
            count[n]++;
        }
        vector<vector<int>>buckets(nums.size()+1);
        for( auto x:count){
            buckets[x.second].push_back({x.first});
        }
        
        vector<int>result;
        for(int i=buckets.size()-1;i>=0;i--){
            for(int n:buckets[i]){
                result.push_back(n);
                if(result.size()==k) return result;
            }
        }
        return result;

        
    }
};
