class Solution {
public:
int m, n;
vector<vector<int>>directions{{1,0}, {-1,0}, {0,1}, {0,-1}}; //direction vector
    void DFS(vector<vector<int>> &grid, int r, int c, int prev_val, vector<vector<bool>> &visited){ //ambiguos visited vector
        if(r<0 || c<0 || r>=m || c>=n ) return; //out of bounds
        if(visited[r][c] == true || grid[r][c] < prev_val) return; //out of bounds

        visited[r][c] = true; //visited

        for(auto &dir: directions){
            int new_r = r + dir[0];
            int new_c = c + dir[1];

            DFS(grid, new_r, new_c, grid[r][c], visited);
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        m = grid.size(); //row 
        n = grid[0].size(); //col

        vector<vector<int>>result; //[[push back the coord], [], [] ]

        vector<vector<bool>>isPacificvisited(m , vector<bool>(n, false)); //can reach to pacific from prev to current
        vector<vector<bool>>isAtlanticvisited(m, vector<bool>(n, false)); //can reach to atalantic from prev to current

        //first row -> pacific, and last row -> atlantic
        for(int j=0; j<n; j++){
            DFS(grid, 0, j, INT_MIN, isPacificvisited); //first  row -> (0, 1), (0, 2) , (0,3) ...
            DFS(grid, m-1, j, INT_MIN, isAtlanticvisited); //last row -> (m-1, 1), (m-1, 2), (m-1, 3) ...
        }

        //first column -> pacific, last column -> atlantic
        for(int i=0; i<m; i++){
            DFS(grid, i, 0, INT_MIN, isPacificvisited); //first column -> (1,0), (2,0), (3, 0) ...
            DFS(grid, i, n-1, INT_MIN, isAtlanticvisited); //last column ->  (1, n-1), (2, n-1), (3, n-1) ...
        }

        //iterate through the matrix and if the cell can reach both pacific and atlantic then push to the result
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isPacificvisited[i][j] && isAtlanticvisited[i][j]){
                    result.push_back({i, j}); //push the coordinate into the result vector
                }
            }
        }

        return result;
    }
};