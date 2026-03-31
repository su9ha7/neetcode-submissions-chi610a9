
class NumMatrix {
private:
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        // Step 1: Initialize prefix matrix with extra row/col for padding
        prefix.assign(rows + 1, vector<int>(cols + 1, 0));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // Step 2: Fill the table using the 2D prefix sum formula
                prefix[r + 1][c + 1] = matrix[r][c] + prefix[r][c + 1] + 
                                       prefix[r + 1][c] - prefix[r][c];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        // Step 3: O(1) retrieval using inclusion-exclusion
        return prefix[r2 + 1][c2 + 1] - prefix[r1][c2 + 1] - 
               prefix[r2 + 1][c1] + prefix[r1][c1];
    }
};