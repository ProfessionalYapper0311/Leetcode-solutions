class Solution {
public:
int m;
int n;
    vector<vector<int>>directions{{1, 0},{-1, 0},{0, 1},{0, -1}}; //up down right left

    bool find(vector<vector<char>>& board, int i, int j, int idx, string& word){
        if(idx == word.length()) return true; //word all found

        if( i<0 || j<0 || i>=m || j>=n || board[i][j] == '#' /*visted*/){
            return false;
        } //out of bounds

        if(board[i][j] != word[idx]) return false; //word not found

        char temp = board[i][j]; 
        board[i][j] = '#';

        //calc new direction for the new woor dor idx+1
        for(auto &dir: directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(find(board, new_i, new_j, idx+1, word)){
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0] && find(board, i, j, 0, word)){
                    return true;
                }
            }
        }
        return false;
    }
};