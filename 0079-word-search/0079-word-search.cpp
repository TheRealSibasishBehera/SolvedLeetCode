class Solution {
public:



bool helper(string &curr, vector<vector<char>> &board, vector<vector<int>> &clone, string &word, int i, int j, int index)
{
    // Check if the current sequence matches the target word
    if (index == word.size())
        return true;

    // Check if the current cell is out of bounds or already visited
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || clone[i][j] != -1 || board[i][j] != word[index])
        return false;

    // Set it to 1 to mark it as visited
    clone[i][j] = 1;
    curr.push_back(board[i][j]);

    // Try exploring all possible paths
    if (helper(curr, board, clone, word, i + 1, j, index + 1) ||
        helper(curr, board, clone, word, i - 1, j, index + 1) ||
        helper(curr, board, clone, word, i, j + 1, index + 1) ||
        helper(curr, board, clone, word, i, j - 1, index + 1))
    {
        return true;
    }

    // Reset the cell to -1 and pop the last character from curr
    clone[i][j] = -1;
    curr.pop_back();

    return false;
}

bool exist(vector<vector<char>> &board, string &word)
{
    // direction u can go a point is
    // i+1,i-1,j+1,j-1
    // thing u need to keep track of the things u covered

    // Iterate through each cell to start the search
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            // If the starting character matches, start the search
            if (board[i][j] == word[0])
            {
                vector<vector<int>> clone(board.size(), vector<int>(board[0].size(), -1));
                string curr = "";
                if (helper(curr, board, clone, word, i, j, 0))
                {
                    return true;
                }
            }
        }
    }

    return false;
}


};