class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for( int r=0;r<9;r++){
            unordered_set<int>seen;
            for(int c =0;c<9;c++){
                if(board[r][c]=='.')continue;
                if(seen.count(board[r][c])) return false;
                seen.insert(board[r][c]);
            }
        }
        for( int c=0;c<9;c++){
            unordered_set<int>seen;
            for(int r=0;r<9;r++){
                if(board[r][c]=='.')continue;
                if(seen.count(board[r][c]))return false;
                seen.insert(board[r][c]);

            }
        }
        for(int r=0;r<9;r+=3){
            for(int c=0;c<9;c+=3){
                unordered_set<char>seen;
                for( int i=0;i<3;i++){
                    for( int j=0;j<3;j++){
                        char curr = board[r+i][c+j];
                        if(curr=='.')continue;
                        if(seen.count(curr)) return false;
                        seen.insert(curr);
                    }
                }
            }
        }
        return true;
        
        
    }
};
