class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Line 1: Set up the two pointers at the grid boundaries.
        int left = 0;
        int right = numbers.size() - 1;

        // Line 2: Keep 'squeezing' until the pointers meet.
        while (left < right) {
            int current_sum = numbers[left] + numbers[right];

            // Line 3: If we found the target, return indices (1-indexed).
            if (current_sum == target) {
                return {left + 1, right + 1}; 
            }
            
            // Line 4: If sum is too small, move Left marker to a bigger value.
            else if (current_sum < target) {
                left++;
            }
            
            // Line 5: If sum is too big, move Right marker to a smaller value.
            else {
                right--;
            }
        }
        
        return {}; // Will not be reached since exactly one solution exists.
    }
};