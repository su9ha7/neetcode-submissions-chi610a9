class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> seen;
        seen[0]=1;
        int curr_sum=0;
        int count =0;
        for(int i=0;i<nums.size();i++){
            curr_sum += nums[i];
            int x = curr_sum -k;
            if( seen.find(x)!=seen.end()){
                count +=seen[x];
            }
            seen[curr_sum]++;
        }
        return count;
        
    }
};