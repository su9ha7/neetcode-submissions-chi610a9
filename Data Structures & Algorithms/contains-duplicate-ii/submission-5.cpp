class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> memory; 

    for (int i = 0; i < nums.size(); i++) {
        int current_val = nums[i];

        // Have we seen this number before?
        if (memory.find(current_val) != memory.end()) {
            // Calculate distance between current index and old index
            if (i - memory[current_val] <= k) {
                return true; // Found a pair within distance k!
            }
        }
        
        // Update the index of the number in our memory
        // This is important because the "newest" index is the closest 
        // to any future duplicates.
        memory[current_val] = i; 
    }

    return false; // No such pair found
}
        
    }
;