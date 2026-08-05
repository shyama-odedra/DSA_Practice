class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int liveNeighbors = 0;
                for (int x = -1; x <= 1; ++x) {
                    for (int y = -1; y <= 1; ++y) {
                        if (x == 0 && y == 0) continue;
                        int r = i + x;
                        int c = j + y;
                        if (r >= 0 && r < m && c >= 0 && c < n && (board[r][c] & 1)) {
                            liveNeighbors++;
                        }
                    }
                }
                
                if ((board[i][j] & 1) && (liveNeighbors == 2 || liveNeighbors == 3)) {
                    board[i][j] |= 2;
                } else if (!(board[i][j] & 1) && liveNeighbors == 3) {
                    board[i][j] |= 2;
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};