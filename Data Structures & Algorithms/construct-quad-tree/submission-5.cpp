/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* constructRange(vector<vector<int>>& grid, int r , int c  , int length) {
        bool isSame = true;
        int val = grid[r][c];
        for( int i = r;i<r+length ; i++){
            for(int j = c;j<c+length ; j++){
                if( grid[i][j]!=val){
                    isSame = false;
                    break;
                }

            }
            if(!isSame) break;
        }
        if(isSame){
            return new Node (val==1 , true);
        }
        int half = length / 2;
        Node* topLeftNode     = constructRange(grid, r, c, half);
        Node* topRightNode    = constructRange(grid, r, c + half, half);
        Node* bottomLeftNode  = constructRange(grid, r + half, c, half);
        Node* bottomRightNode = constructRange(grid, r + half, c + half, half);

        // Return internal node with 4 children
        return new Node(true, false, topLeftNode, topRightNode, bottomLeftNode, bottomRightNode);
        

        

        
    }
    public :
    Node*construct(vector<vector<int>>& grid){
        int n = grid.size();
        return constructRange(grid,0,0,n);
    }
};