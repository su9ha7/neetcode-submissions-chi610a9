class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> char_set;
        int l =0;
        int max_length =0;
        for( int r =0;r<s.length();r++){
            while(char_set.find(s[r])!=char_set.end()){
                char_set.erase(s[l]);
                l++;
            }
            char_set.insert(s[r]);
            max_length = max(max_length,r-l+1);
        }
        return max_length;
    }
};
