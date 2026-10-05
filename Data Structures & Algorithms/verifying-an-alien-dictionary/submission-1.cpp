class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int rank[26];
        for( int i=0;i<order.size();i++){
            rank[order[i]-'a'] = i;
        }
        for( int i =0;i<words.size()-1;i++){
           string w1 = words[i];
           string w2 = words[i+1];
            bool foundDifference = false;
            int minLen = min(w1.size(),w2.size());
            for(int j=0;j<minLen;j++){
                if(w1[j]!=w2[j]){
                    if(rank[w1[j]-'a']>rank[w2[j]-'a']){
                        return false;
                    }
                    foundDifference = true;
                    break;
                }
            }
            if(!foundDifference && w1.size()>w2.size()){
                return false;
            }
        }
        return true;
    }
};