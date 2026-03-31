class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int ,int> seen ;
        vector<int>result;
        int n = nums.size();
        for( int i=0;i<nums.size();i++){
            seen[nums[i]]++;
        }
        for(auto it : seen){
            if(it.second>n/3){
                result.push_back(it.first);
            }
        }
        return result;
    }
};