class Solution {
    boolean isSafe(int r ,int c,char[][] queens, int n  ){
        int dr = r;
        int dc = c;
        //left row;
        while(dc >= 0){
            if(queens[dr][dc] == 'Q')return false;
            dc--;
        }
        //top-left diagonal
        dr = r;
        dc = c;
        while(dc >=0 && dr >= 0){
            if(queens[dr][dc] == 'Q')return false;
            dc--;
            dr--;

        }
        //bottom-left
        dc =c;
        dr = r;
        while(dr<n && dc >=0 ){
            if(queens[dr][dc] == 'Q')return false;
            dr++;
            dc--;
        }
        return true;
    }
    void solve(int n  , List<List<String>> lst , char[][] queens , int col){
        if(col == n){
            List<String > ans = new ArrayList();
            for(char[] rowarr :  queens){
            ans.add(new String(rowarr));
            }
            lst.add(ans);
            return ;
        }

        for(int row = 0  ; row <  n;  row++ ){
            if(isSafe(row, col , queens ,n)){
                queens[row][col] = 'Q';
                solve(n, lst , queens, col+1);
                queens[row][col] = '.';
            }
        }
    } 
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> lst = new ArrayList<>();
        char [][] queens = new char[n][n];
        for(int i  = 0 ; i  < n ; i++){
            Arrays.fill(queens[i] , '.');
        }
        solve( n , lst , queens , 0);
        return lst;
    }
}