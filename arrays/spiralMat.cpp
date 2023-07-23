
// Given a matrix of size r*c. Traverse the matrix in spiral form.



vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ans;
        int startingRow = 0;
        int endingRow = r-1;
        int startingCol = 0;
        int endingCol = c-1;
        
        int total = r*c;
        int count = 0;
        
        while(count < total){
            
            for(int index = startingCol; count < total && index <= endingCol; index++){
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            
            for(int index = startingRow; count < total && index <= endingRow; index++){
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            
            for(int index = endingCol; count < total && index >= startingCol; index--){
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            
            for(int index = endingRow; count < total && index >= startingRow; index--){
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }