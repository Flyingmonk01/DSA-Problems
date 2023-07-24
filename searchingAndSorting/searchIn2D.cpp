// Given a matrix mat[][] of size N x M, where every row and column is sorted in increasing order, and a number X is given. The task is to find whether element X is present in the matrix or not.


int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
	    for(int i = 0; i < N; i++){
	        for(int j = 0; j < M; j++){
	            if(mat[i][j] == X) return 1;
	        }
	    }
	    return 0;
	}



//     You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.



bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int start = 0;
        int end = row*col - 1;
        
        int mid = start + (end-start)/2;
        while(start <= end){
            
            int element = matrix[mid/col][mid%col];
            
            if(element == target){
                return 1;
            }
            else if(element > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            mid = start + (end-start)/2;
        }
        return 0;
    }