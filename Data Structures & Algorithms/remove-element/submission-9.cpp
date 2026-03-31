
class Solution {
public:
    int removeElement(vector<int>& nums,int val) {
        vector<int> temp;
        for(int n : nums) {
            if(n!=val){
            temp.push_back(n);
        }
        }
         int k=0;
        for( int i=0;i<temp.size();i++){
            nums[i]=temp[i];
        }
        return temp.size();
      

        
    }
    
    };
