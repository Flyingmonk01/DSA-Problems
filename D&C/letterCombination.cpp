// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

void getLetterCombination(string digits,vector<string>& map,string output,vector<string>&res, int idx){
        // base case
        if(idx >= digits.length()){ 
            res.push_back(output);
            return ;
        }

        int digit = digits[idx] - '0';
        string value = map[digit];

        for(int i = 0; i < value.length(); i++){
            char ch = value[i];
            getLetterCombination(digits, map, output+ch, res, idx+1); 
        }
    }

    vector<string> letterCombinations(string digits){
        vector<string> map(10);

        if(digits.length() == 0) return {};
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";

        string output = "";
        vector<string> res;
        int idx = 0;

        getLetterCombination(digits, map, output, res, idx);
        return res;
    }






// Given the mobile numeric keypad. You can only press buttons that are up, left, right, or down to the current button or the current button itself (like 00,11, etc.). You are not allowed to press the bottom row corner buttons (i.e. * and # ). Given a number N, the task is to find out the number of possible numbers of the given length.

    char mat[4][3] = {
	    {'1','2','3'},
	    {'4','5','6'},
	    {'7','8','9'},
	    {'*','0','#'}
	};
	
	long long solve(int i, int j, int n, vector<vector<vector<long long>>>& dp){
	    // base case
	    if(i < 0 || i >= 4 || j < 0 || j >= 3) return 0;
	    
	    if(mat[i][j] == '*' || mat[i][j] == '#') return 0;
	    
	    if (n == 1) return 1;
	    
	    if(dp[n][i][j] != -1) return dp[n][i][j];
	    
	    dp[n][i][j] = solve(i, j, n-1, dp) + solve(i-1, j, n-1, dp) + solve(i, j-1, n-1, dp) + solve(i+1, j, n-1, dp) + solve(i, j+1, n-1, dp);
	    
	    return dp[n][i][j];
	}
	    
	long long getCount(int N)
	{
		// Your code goes here
		long long count = 0;
		vector<vector<vector<long long>>>dp(N+1, vector<vector<long long>>(4, vector<long long>(3, -1)));
		for(int i = 0; i < 4; i++){
		    for(int j = 0; j < 3; j++){
		        if(mat[i][j] != '*' || mat[i][j] != '#'){
		            count += solve(i, j, N, dp);
		        }
		    }
		}
		return count;
	}