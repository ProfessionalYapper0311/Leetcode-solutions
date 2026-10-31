class Solution {
public:
int MOD = 1e9 + 7;
int LEFT = 0;
int UP = 1;
int m;
int n;

    //memo = [i][j] = {-1, -1} , 2d vector for i, j and then two values for left and right

    int solve(vector<vector<int>>& grid, int i, int j, int cameFrom, vector<vector<array<int, 2>>> &memogrid){
        if(i >= m || j >= n) return 0; //invalid path
        if(i == m-1 && j== n-1) return 1; //reached the end path

        if(memogrid[i][j][cameFrom] != -1){ //value has been found
            return memogrid[i][j][cameFrom]; //memo
        }
        if(grid[i][j] == 1){
            if(cameFrom == LEFT){
                return memogrid[i][j][cameFrom] = solve(grid, i+1, j, UP, memogrid); //moving down so camefrom is up
            }
            else{
                return memogrid[i][j][cameFrom] = solve(grid, i, j+1, LEFT, memogrid); //moving right so camefrom = left
            }
        }

        //GRID[I][J] == 0
        int totalpathcount = 0;
        totalpathcount = (totalpathcount + solve(grid, i, j+1, LEFT, memogrid)) % MOD;
        totalpathcount = (totalpathcount + solve(grid, i+1, j, UP, memogrid)) % MOD;
        return memogrid[i][j][cameFrom] = totalpathcount;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        //memoization
        vector<vector<array<int, 2>>> memogrid( m+1, vector<array<int , 2>> (n, {-1, -1}) ); //create m+1 array of 2 and fill the n columns of them with {-1, -1}
        return solve(grid, 0, 0, LEFT, memogrid); //robot starts from here, start the recursion
    }
};

//memoize after recursion