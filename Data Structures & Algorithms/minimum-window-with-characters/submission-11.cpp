class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        
        vector<int> countT(128, 0); 
        vector<int> window(128, 0); 
        for (char c : t) countT[c]++;

        int have = 0, need = 0;
        for (int i = 0; i < 128; i++) {
            if (countT[i] > 0) need++;
        }

        int left = 0;
        int min_len = INT_MAX;
        int start_index = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            window[c]++;
            
            if (countT[c] > 0 && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    start_index = left;
                }

                char leftchar = s[left];
                window[leftchar]--;

                if (countT[leftchar] > 0 && window[leftchar] < countT[leftchar]) {
                    have--;
                }
                left++;
            } 
        } 

        return (min_len == INT_MAX) ? "" : s.substr(start_index, min_len);
    } 
};