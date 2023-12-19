#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int no_row = matrix.size();
        if (no_row == 0) {
            return false;
        }

        int no_col = matrix[0].size();
        int total_elements = no_col * no_row;
        int start = 0;
        int end = total_elements - 1;

        while (start <= end) {
            int middle = start + (end - start) / 2;
            // figure out row and columns;
            int r = middle / no_col; // Corrected the calculation of row
            int col = middle % no_col;

            if (matrix[r][col] == target) {
                return true;
            } else if (matrix[r][col] < target) {
                start = middle + 1;
            } else {
                end = middle - 1;
            }
        }

        return false;
    }
};
