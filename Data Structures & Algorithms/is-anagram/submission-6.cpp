class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<int,char>seen;
        for( int i=0 ;i<s.length();i++){
           seen[ s[i]]++;
           seen[ t[i]]--;
        }
        for( auto x : seen){
            if(x.second!=0){
                return false;
            }

        }
        return true;

        
    }
};
