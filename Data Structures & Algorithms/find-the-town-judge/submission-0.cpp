class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustscore(n+1,0);
        for( const auto& relation : trust){
            int a = relation[0];
            int b = relation[1];
            trustscore[a]--;
            trustscore[b]++;
        }
        for( int i =1;i<=n;i++){
            if(trustscore[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};