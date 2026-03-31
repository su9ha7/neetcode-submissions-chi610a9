class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string encoded ="";
        char delimiter = (char)31;
        for( const string&s:strs){
            encoded+=  s + delimiter;
        }
        return encoded;

    }

    vector<string> decode(string s) {
        if(s.empty()) return{};
        vector <string> decoded;
        char delimiter =(char)31;
        string temp ="";
        for(int i=0;i<s.length();i++) {
            if(s[i]==delimiter){
                decoded.push_back(temp);
                temp ="";
            }
            else{
                temp+=s[i];
            }
        }
        return decoded;

    }
};
