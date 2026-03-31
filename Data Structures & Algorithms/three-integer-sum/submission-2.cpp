class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        // Step 1: Sort the array (Essential for two-pointer approach)
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < (int)nums.size(); i++) {
            // Optimization: If the current number is > 0, the sum can't be 0
            if (nums[i] > 0) break;

            // Step 2: Skip duplicates for the 'anchor' number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = (int)nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++; // Sum too small, move left pointer to a larger value
                } else if (sum > 0) {
                    right--; // Sum too large, move right pointer to a smaller value
                } else {
                    // Step 3: Found a triplet!
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    // Step 4: Skip duplicate values for left and right
                    int last_left = nums[left];
                    int last_right = nums[right];
                    while (left < right && nums[left] == last_left) left++;
                    while (left < right && nums[right] == last_right) right--;
                }
            }
        }
        return res;
    }
};
        
    

