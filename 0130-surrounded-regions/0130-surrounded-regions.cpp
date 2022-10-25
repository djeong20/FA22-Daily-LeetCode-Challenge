class Solution {
public:
    void bfs(vector<vector<char>>& board, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        int r, c;
        
        queue<pair<int, int>> q;
        q.push({x,y});
        board[x][y] = '.';
        
        while (!q.empty()) {
            r = q.front().first;
            c = q.front().second;
            q.pop();
            
            if (r > 0 && board[r-1][c] == 'O') {
                q.push({r-1, c});
                board[r-1][c] = '.';
            }
            if (r < m-1 && board[r+1][c] == 'O') {
                q.push({r+1, c});
                board[r+1][c] = '.';
            }
            if (c > 0 && board[r][c-1] == 'O') {
                q.push({r, c-1});
                board[r][c-1] = '.';
            }
            if (c < n-1 && board[r][c+1] == 'O') {
                q.push({r, c+1});
                board[r][c+1] = '.';
            }
        }
    }

    
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        if (m <= 2 || n <= 2) return;
        
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') bfs(board, i, 0);
            if (board[i][n-1] == 'O') bfs(board, i, n-1);
        }
        
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') bfs(board, 0, i);   
            if (board[m-1][i] == 'O') bfs(board, m-1, i);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '.') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    
    // iterate border and save visited O's connected to edge (bfs)
    // iterate matrix 1~n and flip using bfs
};