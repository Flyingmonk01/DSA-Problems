
// Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

 
    bool isSafe(int i, int j, int grid[N][N], int val){
        for(int k = 0; k < N; k++){
            if(grid[k][j] == val) return false;
            
            if(grid[i][k] == val) return false;
            
            if(grid[3*(i/3) +(k/3)][3*(j/3)+(k%3)] == val) return false;
        }
        return true;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 0){
                    for(int val = 1; val <= 9; val++){
                        if(isSafe(i, j, grid, val)){
                            grid[i][j] = val;
                            bool nextSol = SolveSudoku(grid);
                            if(nextSol){
                                return true;
                            }
                            else{
                               grid[i][j] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }