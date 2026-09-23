#include<iostream>
#include<vector>
class Solution {
    private:
    int backtrack(const std:: vector<int>& nums , int index, int currentXor){
        if(index==nums.size()){
            return currentXor;
        }
        int include = backtrack(nums, index+1,currentXor^nums[index]);
        int exclude = backtrack( nums , index+1,currentXor);
        return include + exclude ;
    }
    public :
    int subsetXORSum(std::vector<int>& nums){
        return backtrack(nums,0,0);
    }
};