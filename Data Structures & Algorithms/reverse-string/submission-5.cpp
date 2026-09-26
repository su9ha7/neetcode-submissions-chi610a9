class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char>temp;
        for(int i =s.size()-1;i>=0;i--){
            temp.push_back(s[i]);
        }
        for( int i=0;i<s.size();i++){
            s[i]=temp[i];
        }

        
    }
};