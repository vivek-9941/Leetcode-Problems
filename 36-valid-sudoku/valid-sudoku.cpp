class Solution {
    bool solve(vector<vector<char>>& board,int r, int c){
        int dr = r-1;
        int dc = c;
        while(dr >= 0 ){
            if(board[r][c] == board[dr][dc])return false;
            dr--;
        }
        dr = r;
        dc = c-1;
        while(dc>=0){
            if(board[r][c] == board[dr][dc] )return false;
            dc--;
        }
        int start = (r/3)*3;

        int colstart  = (c/3 ) *3;
        for(int i =start; i  < r ; i++){
            for(int j = colstart ; j < colstart + 3 ;j++){
                if(board[i][j] == board[r][c])return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n  = board.size();
        int m = board[0].size();
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] != '.' && !solve(board, i ,j))return false;
            }
        }
         return true;
    }
};