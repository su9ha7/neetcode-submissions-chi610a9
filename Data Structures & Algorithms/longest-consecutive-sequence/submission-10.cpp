class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        unordered_set<int> numset(nums.begin(), nums.end());
        int longeststreak = 0; // Use this name consistently

        for (int n : numset) {
            // Check if 'n' is the start of a sequence
            if(numset.find(n - 1) == numset.end()) {
                int currentnum = n;
                int currentstreak = 1;

                // Add braces here to keep both lines in the loop
                while(numset.find(currentnum + 1) != numset.end()) {
                    currentnum++;
                    currentstreak++;
                }
                
                // Use the same name 'longeststreak'
                longeststreak = max(longeststreak, currentstreak);
            }
        }
        return longeststreak; 
    }
};