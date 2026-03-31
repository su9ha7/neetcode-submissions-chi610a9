class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res; // Fixed: added missing '>'
        int n = nums.size(); // Fixed: defined n
        if (n < 4) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // Fixed: Check nums[j] against nums[j-1]
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = n - 1;

                // Fixed: Must be left < right to start the squeeze
                while (left < right) {
                    // Casting to long long prevents overflow errors
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        int last_left = nums[left]; // Fixed: semicolon instead of comma
                        int last_right = nums[right];
                        
                        while (left < right && nums[left] == last_left) left++;
                        while (left < right && nums[right] == last_right) right--;
                    }
                }
            }
        }
        return res; // Fixed: moved outside all loops
    }
};