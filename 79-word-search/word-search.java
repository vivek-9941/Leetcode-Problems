class Solution {
    int drow[] = { 0, 1, 0, -1 };
    int dcol[] = { 1, 0, -1, 0 };

    boolean solve(char[][] board, int i, int j, String word, int index, int[][] vis) {
        if (word.length() == index)
            return true;
        
        if (i < 0  || j < 0 || j >= board[0].length || i >= board.length || vis[i][j] == 1 ||  word.charAt(index) != board[i][j]) return false;
        vis[i][j] = 1;
         for (int k = 0; k < 4; k++) {
            int nrwo = drow[k] + i;
            int ncol = dcol[k] + j;
            // vis[nrwo][ncol] = 1;
            if(solve(board, nrwo, ncol, word, index + 1, vis))return true;
            
        }
                vis[i][j] = 0;
        return false;
    }

    public boolean exist(char[][] board, String word) {
        int[][] vis = new int[board.length][board[0].length];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == word.charAt(0)) {
                    if (solve(board, i, j, word, 0, vis))
                        return true;
                }
            }
        }
        return false;
    }
}