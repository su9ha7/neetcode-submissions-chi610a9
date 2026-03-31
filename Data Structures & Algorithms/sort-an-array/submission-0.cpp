class Solution {
public:
void merge(vector<int>&nums,int left, int mid,int right){
    vector<int>temp;
    int i =left;
    int j = mid+1;
    while(i<=mid && j<=right){
        if(nums[i]<=nums[j]){
            temp.push_back(nums[i++]);
        }
        else {
            temp.push_back(nums[j++]);
        }
    }
    while(i<=mid) temp.push_back(nums[i++]);
    while(j<=right) temp.push_back(nums[j++]);
    for(int k=0;k<temp.size();k++){
        nums[left + k]= temp[k];
    }
}
void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return; // Base case: 1 element left

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);      // Split left side
        mergeSort(nums, mid + 1, right); // Split right side
        
        merge(nums, left, mid, right);   // Merge them together
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

     

        
    


;