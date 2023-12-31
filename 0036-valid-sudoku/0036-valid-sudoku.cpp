class Solution {
public:
    
    
bool isValidSudoku(vector<vector<char>> &board)
{
    //we will use 3 hashmaps
    //one for row
    //one for col
    //one for 3*3 matrix
    unordered_set<int> row[9];
    unordered_set<int> col[9];
    unordered_set<int> matrix[3][3];

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == '.')
                continue;
            int curr = board[i][j] - '0';
            if (row[i].find(curr) != row[i].end())
                return false;
            if (col[j].find(curr) != col[j].end())
                return false;

            //this is the tricky part
            //we have to find the matrix number
            //it belongs to 
            // its always i/3 and j/3

            if(matrix[(i/3)][j/3].find(curr) != matrix[(i/3)][j/3].end())
                return false;

            row[i].insert(curr);
            col[j].insert(curr);
            matrix[i/3][j/3].insert(curr);  
        }
        
    }

    return true;
    
}
};