class Solution {
public:
typedef pair<int, int> P; //since we are storign coordinates
vector<vector<int>> directions{ {0, 1}, {0, -1}, {1, 0}, {-1, 0}}; //direction vector 

    int orangesRotting(vector<vector<int>>& grid) {
        //setup -> queue and no. of fresh og
        int row = grid.size();
        int col = grid[0].size();

        queue<P> que;//create the queue

        int fresh_og = 0; 

        for(int i = 0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 2){
                    que.push({i, j}); //push the rotten og to queue
                }
                if(grid[i][j] == 1){
                    fresh_og ++; //no. of fresh orange
                }
            }
        }

        //if no fresh og
        if(fresh_og == 0) return 0;

        //multi_source bfs
        int min_count = 0;

        while(!que.empty()){
            int n = que.size();

            while(n--){
                P curr = que.front();
                que.pop();

                int i = curr.first;
                int j = curr.second;

                for(auto &dir: directions){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i>=0 && new_j>=0 && new_i < row && new_j < col && grid[new_i][new_j] == 1){ //is safe and fresh
                        que.push({new_i, new_j}); //found a fresh push to queue
                        grid[new_i][new_j] = 2; //rot the fresh orange
                        fresh_og --;
                    }
                }
                
            }
            min_count++;
        }
        //no more fresh og? min_count -1 or else -1
        return (fresh_og == 0) ? (min_count - 1) : -1;
    }
};

//tc = o(m.n) or o(row * col), bfs
//sc = o(row.col); worst case all rotten orange so iterate thorugh all matrix and store o(row.col) elements