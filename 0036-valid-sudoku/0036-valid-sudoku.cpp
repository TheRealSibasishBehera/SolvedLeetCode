class Solution {
public:
    
bool isValidSudoku(vector<vector<char>> &board)
{
    // We will use arrays instead of unordered_set
    // One array for each row, column, and 3*3 matrix
    int row[9][10] = {0};  // 10-sized array to track the occurrence of digits 1-9
    int col[9][10] = {0};
    int matrix[3][3][10] = {0};

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
                continue;

            int curr = board[i][j] - '0';

            // Check if the current digit already exists in the corresponding row, column, or matrix
            if (row[i][curr] == 1)
                return false;
            if (col[j][curr] == 1)
                return false;
            if (matrix[i / 3][j / 3][curr] == 1)
                return false;

            // Mark the current digit as seen in the row, column, and matrix
            row[i][curr] = 1;
            col[j][curr] = 1;
            matrix[i / 3][j / 3][curr] = 1;
        }
    }

    return true;
}
};