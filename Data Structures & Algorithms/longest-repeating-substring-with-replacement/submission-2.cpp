class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>counts(128,0);
        int left =0;
        int max_freq =0;
        int max_length =0;
        for ( int right =0;right<s.length();right++){
            counts[s[right]]++;
            max_freq = max( max_freq,counts[s[right]]);
            while((right-left+1)-max_freq>k){
                counts[s[left]]--;
                left++;
            }
            max_length = max( max_length,right-left+1);

        }
        return max_length;
    }
};
