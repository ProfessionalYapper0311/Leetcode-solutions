class Solution {
public:
int N; //global to pass board size
    bool isValid(vector<string>&board, int row, int col){
        //look up -> row-1 to 0
        for(int i= row-1; i>=0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        //left diagonal, so i-1, j-1, there row-1 to 0 and col- 1 to 0 
        //no nested loop
        for(int i = row-1, j = col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        //right diagonal, i-1, j+1, row-1 to 0 and col + 1 to n
        for(int i=row-1,j=col+1; i>=0 && j<N; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }
    void solve(vector<string>&board, int row ,vector<vector<string>>&result){
        if(row >= N){ //since we are passing row, base case check is row<n
        result.push_back(board);
        return;
        }

        for(int col=0; col<N; col++){

            if(isValid(board, row, col)){ //checks if till 0-row-1, all queens placed are valid
            
                board[row][col] = 'Q'; //mark Q
                solve(board, row+1, result); //backtrack trust
                board[row][col] = '.'; //bad decion made, revert

            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string>board(n, string(n, '.')); //board {"..." , "..." , "..."}
        vector<vector<string>>result; //store the board
                
        solve(board, 0, result); //pass row = 0;

        return result;

    }
};