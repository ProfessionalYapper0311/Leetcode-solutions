#    //so basically a clever way to do is that iterate through the border
#    //if o found convert it to T
#    //iterate though the grid and convert o to X
#    //top row -> 0, col
#    //bottom row -> m-1, col
#    //first column -> row, 0
#    //last column -> row, n-1
class Solution:
    def solve(self, board: list[list[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m, n = len(board), len(board[0])

        def capture(r,c): #dfs
            if (r<0 or r>=m or c<0 or c>=n or board[r][c] != "O"):
                return 
            
            board[r][c] = "T"
            directions = [(0,1),(0,-1),(1,0),(-1,0)]
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                capture(nr, nc)
            
        #capture the unsorrounded regions
        for r in range(m):
            for c in range(n):
                if( board[r][c] == "O" and (r in [0, m-1] or c in [0, n-1])):
                    capture(r, c)
            
        #capture the unsorrounded region
        for r in range(m):
            for c in range(n):
                if board[r][c] == "O":
                    board[r][c] = "X"
            
        #uncapture the unsorrounded region
        for r in range(m):
            for c in range(n):
                if board[r][c] == "T":
                    board[r][c] = "O"

                        