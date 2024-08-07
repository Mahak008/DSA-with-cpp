bool isSafe(int row, int col, vector<string> board, int n) {
    int r = row, c = col;
    while (r >= 0 && c >= 0) {
        if (board[r][c] == 'Q')
            return false;
        r--;
        c--;
    }

    r = row, c = col;
    while (c >= 0) {
        if (board[r][c] == 'Q')
            return false;
        c--;
    }

    r = row, c = col;
    while (r < n && c >= 0) {
        if (board[r][c] == 'Q')
            return false;
        r++;
        c--;
    }

    return true;
}

void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans) {
    if (col == n) {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, n, board, ans);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');

    for (int i = 0; i < n; i++) {
        board[i] = s;
    }

    solve(0, n, board, ans);
    return ans;
}

// Input: n = 4
// Output: . Q . .
//         . . . Q
//         Q . . .
//         . . Q .
  
// Another Output  
//         . . Q .
//         Q . . .
//         . . . Q
//         . Q . . 
