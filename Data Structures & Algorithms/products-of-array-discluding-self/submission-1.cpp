class Solution {
    public:
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 1);
    
    int left = 1;
    for (int i = 0; i < n; i++) {
        res[i] = left; // Store product of all elements to the left
        left *= nums[i];
    }
    
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
        res[i] *= right; // Multiply by product of all elements to the right
        right *= nums[i];
    }
    return res;
}
};
