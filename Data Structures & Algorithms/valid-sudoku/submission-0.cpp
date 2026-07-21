class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> square(9);
        vector<unordered_set<int>> col(9);

        for (int i = 0; i < 9; i++) {
            unordered_set<int> row;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                if (row.find(board[i][j]) != row.end()) return false;
                else row.insert(board[i][j]);

                if (col[j].find(board[i][j]) != col[j].end()) return false;
                else col[j].insert(board[i][j]);

                int ind = (i / 3) * 3 + (j / 3);
                if (square[ind].find(board[i][j]) != square[ind].end()) return false;
                else square[ind].insert(board[i][j]);
            }
        }

        return true;
    }
};
