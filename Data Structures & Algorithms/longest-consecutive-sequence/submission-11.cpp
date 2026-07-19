class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if( nums.empty()) return 0;
        unordered_set<int>numset(nums.begin(),nums.end());
        int longeststreak =0;
        for( int n:numset){
            if(numset.find(n-1)==numset.end()){
                int currentnum =n;
                int currentstreak =1;
                while(numset.find(currentnum+1)!=numset.end()){
                    currentnum++;
                    currentstreak++;
                }
                longeststreak = max( longeststreak,currentstreak);
            }
        }
        return longeststreak;
        
    }
};
