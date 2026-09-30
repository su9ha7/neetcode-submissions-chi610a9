#include<vector>
#include<algorithm>
class Solution{
    private:
    void backtrack(std:: vector<int>path, std:: vector<bool>& visited, const std::vector<int>& nums,std::vector<std::vector<int>>& result){
        if( path.size()==nums.size()){
            result.push_back(path);
            return ;
        }
        for( int i =0; i<nums.size();i++){
            if(visited[i]){
                continue;
            }
            if(i>0 && nums[i]==nums[i-1] && !visited[i-1]){
                continue;
            }
            visited[i] = true ;
            path.push_back(nums[i]);
            backtrack(path, visited, nums, result);
            path.pop_back();
            visited[i]=false;

        }
    }

public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        std::vector<bool> visited(nums.size(), false);

        // Step 1: Sort to bring duplicates together
        std::sort(nums.begin(), nums.end());

        backtrack(path, visited, nums, result);
        return result;
    }
};