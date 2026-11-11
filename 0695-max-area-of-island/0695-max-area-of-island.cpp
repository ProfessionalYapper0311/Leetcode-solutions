class Solution {
public:
int m, n;
vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};//dir vector

int solve(vector<vector<int>>& grid, int i, int j){
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0){
        return 0;
    } //base case 1

    grid[i][j] = 0; //visited, int grid, dolla has an ascii value of 36, so bad choice

    int area = 1;

    for(auto &dir:directions){
        int new_i = i + dir[0];
        int new_j = j + dir[1];

        area += solve(grid, new_i, new_j);
    }
    return area;
}

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        } //no grid, return 0 

        m = grid.size();
        n = grid[0].size();
        int max_area = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    max_area = max(max_area, solve(grid, i , j));
                }
            }
        }
        return max_area;
    }
};