


// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.


bool isSafe(int row, int col, int x, int y, vector<vector<int>> &m, vector<vector<int>> &visited){
        if((x >= 0 && x < row) && (y >= 0 && y < col) &&( m[x][y] == 1) && (visited[x][y] == 0)){
            return true;
        }
        else{
            return false;
        }
    }
    
    void solve(vector<vector<int>> &m, int n, vector<string>& ans, string path, int& row, int& col, int x, int y, vector<vector<int>> &visited){
        if(x == row-1 && y == col-1){
            ans.push_back(path);
            return;
        }
        
        if(isSafe(row, col, x+1, y, m, visited)){
            visited[x+1][y] = 1;
            solve(m, n, ans, path+'D', row, col, x+1, y, visited);;
            visited[x+1][y] = 0;
        }
        
        if(isSafe(row, col, x, y-1, m, visited)){
            visited[x][y-1] = 1;
            solve(m, n, ans, path+'L', row, col, x, y-1, visited);
            visited[x][y-1] = 0;
        }
        
        if(isSafe(row, col, x, y+1, m, visited)){
            visited[x][y+1] = 1;
            solve(m, n, ans, path+'R', row, col, x, y+1, visited);
            visited[x][y+1] = 0;
        }
        
        if(isSafe(row, col, x-1, y, m, visited)){
            visited[x-1][y] = 1;
            solve(m, n, ans, path+'U', row, col, x-1, y, visited);
            visited[x-1][y] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string path = "";
        int row = n, col = n;
        if(m[0][0] == 0) return ans;
        
        int x = 0, y = 0;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
    
        solve(m, n, ans, path, row, col, x, y, visited);
        return ans;
    }