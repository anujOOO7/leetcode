class Solution {
public:
    int count = 0;
    bool safe(int r, int c, vector<string> &board)
    {
        for (int i = r; i >= 0; i--)
        {
            if (board[i][c] == 'Q')
                return false;
        }
        for (int i = r, j = c; i >= 0 && j >= 0; --i, --j)
            if (board[i][j] == 'Q')
                return false;

        for (int i = r, j = c; i >= 0 && j < board.size(); --i, ++j)
            if (board[i][j] == 'Q')
                return false;
        return true;
    }
    int f(int row, vector<string> &board)
    {
        if (row == board.size())
        {
            count++;
            return count;
        }

        for (int col = 0; col < board.size(); col++)
        {
            if (safe(row, col, board))
            {
                board[row][col] = 'Q';
                f(row + 1, board);
                board[row][col] = '.';
            }
        }
        return count;
    }
    int totalNQueens(int n) {
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        return f(0, board);
    }
};