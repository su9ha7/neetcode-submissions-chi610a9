class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // CONTEXT: If the array is empty, there are 0 unique elements.
        if (nums.empty()) return 0;

        // CONTEXT: 'i' is the WRITER. It marks the last "safe" unique spot.
        // We start at 0 because the first element is always unique.
        int i = 0; 

        // CONTEXT: 'j' is the SCANNER. It starts at index 1 and 
        // explores every box in the grid from left to right.
        for (int j = 1; j < nums.size(); j++) {
            
            // CONTEXT: We compare what the Scanner sees (nums[j]) 
            // with our last confirmed unique number (nums[i]).
            if (nums[j] != nums[i]) {
                
                // CONTEXT: If they are different, it means the Scanner 
                // found a brand new unique number!
                
                i++;             // 1. Move the Writer to the next empty slot.
                nums[i] = nums[j]; // 2. Write the new number into that slot.
            }
            // CONTEXT: If they WERE the same, we do nothing. 
            // The Scanner just moves to the next box (j++).
        }

        // CONTEXT: The total number of unique elements is the index 'i' + 1.
        // (Example: If the last unique number is at index 2, there are 3 numbers).
        return i + 1; 
    }
};