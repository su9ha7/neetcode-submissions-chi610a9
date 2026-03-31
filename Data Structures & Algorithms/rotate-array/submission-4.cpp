class Solution {
public:
void reversearray( vector<int>&nums, int left,int right){
    while( left<right){
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right --;
    }
}
    void rotate(vector<int>& nums, int k) {
       int n = nums.size();
       k = k % n;
       if(k==0) return ;
       reversearray( nums,0,n-1);
       reversearray( nums,0,k-1);
       reversearray(nums,k,n-1);
    }
};