class Solution {
public:
int m, n;
vector<vector<int>>directions{{1,0},{-1, 0},{0, 1},{0, -1}}; //direction vector

    bool find(vector<vector<char>>& grid, string& word, int i, int j, int idx){
        if(idx == word.length()){
            return true; //base case 3 - last char of the word
        }

        if(i<0 || j<0|| i>=m || j>=n|| grid[i][j] == '$'){
            return false; //base case 1
        }

        if(grid[i][j] != word[idx]){
            return false; //base case 2
        } 

        char temp = grid[i][j];
        grid[i][j] = '$';//mark visited

        for(auto &dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if( find(grid, word, new_i, new_j, idx + 1) ){ 
                //go to the next char now, e.g: 0 was passed, then 1
                return true; //word found
            }
        }
        grid[i][j] = temp; //unvisited again
        return false;
    }
    bool exist(vector<vector<char>>& grid, string word) {
        m = grid.size();
        n = grid[0].size();
 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == word[0] && find(grid, word, i, j, 0 /*word_idx*/)){
                    //found the first word and started the dfs
                    return true;     
                }
            }
        }
        return false;
    }
};