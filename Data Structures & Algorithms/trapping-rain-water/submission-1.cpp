class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int left =0;
        int right = height.size()-1;
        int total_water =0;
        int left_max=0;
        int right_max=0;
        while( left<right){
            left_max = max(left_max,height[left]);
            right_max = max(right_max,height[right]);
            if(left_max<right_max){
                total_water += left_max - height[left];
                left++;
            }
            else{
                total_water += right_max-height[right];
                right--;
            }
        }
        return total_water;
        
    }
};
