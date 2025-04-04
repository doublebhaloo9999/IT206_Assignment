#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check each row
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> row_set;
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                if (row_set.find(c) != row_set.end()) {
                    return false;
                }
                row_set.insert(c);
            }
        }
        
        // Check each column
        for (int j = 0; j < 9; ++j) {
            unordered_set<char> col_set;
            for (int i = 0; i < 9; ++i) {
                char c = board[i][j];
                if (c == '.') continue;
                if (col_set.find(c) != col_set.end()) {
                    return false;
                }
                col_set.insert(c);
            }
        }
        
        // Check each 3x3 sub-box
        for (int box = 0; box < 9; ++box) {
            unordered_set<char> box_set;
            int start_row = (box / 3) * 3;
            int start_col = (box % 3) * 3;
            for (int i = start_row; i < start_row + 3; ++i) {
                for (int j = start_col; j < start_col + 3; ++j) {
                    char c = board[i][j];
                    if (c == '.') continue;
                    if (box_set.find(c) != box_set.end()) {
                        return false;
                    }
                    box_set.insert(c);
                }
            }
        }
        
        return true;
    }
};