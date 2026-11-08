/*

class Solution {
public:
    int m, n;
    vector<vector<int>>directions{ {1, 0},{-1 ,0},{0, 1},{0, -1}}; //direction vector
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == '0'){
            return;
        } //base case 1 - out of bound or 0

        if(grid[i][j] == '$'){
            return;
        } //base case 2 - if already visited
        
        //do not visit them again
        grid[i][j] = '$'; //visited

        for(auto &dir: directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            dfs(grid, new_i, new_j);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n=grid[0].size();
        int count = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

*/
class Solution {
public:
int m, n;
vector<vector<int>>directions{ {1, 0}, {-1 ,0}, {0, 1}, {0, -1} };

    void bfs(vector<vector<char>>& grid, int i, int j){
        queue<pair<int, int>>que; //create a queu
        que.push({i, j}); //push

        grid[i][j] = '$'; // mark visited

        while(!que.empty()){
            auto it = que.front(); //it.first or it.second
            que.pop(); //pop and then push new childrens

            for(auto &dir: directions){
                int new_i = it.first + dir[0]; //new i
                int new_j = it.second + dir[1]; //new j

                if(new_i < 0 || new_j < 0 || new_i >= m|| new_j >= n || grid[new_i][new_j] == '0'){
                    continue; //base case 1
                }
                else if(grid[new_i][new_j] == '$'){
                    continue; //base case 2
                }
                else{
                    que.push({new_i, new_j}); //push the next child
                    grid[new_i][new_j] = '$'; //visited next
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};