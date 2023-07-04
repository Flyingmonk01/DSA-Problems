// Given an integer N representing the number of pairs of parentheses, the task is to generate all combinations of well-formed(balanced) parentheses.


void generateParantheses(int n, int open, int close, vector<string>& ans, string output){
        if(open == 0 && close == 0){
            ans.push_back(output);
            return;
        }
        
        // include (
        if(open > 0){
            output.push_back('(');
            generateParantheses(n, open-1, close, ans, output);
            output.pop_back();
        }
                    
        // include )
        if(close > open){
            output.push_back(')');
            generateParantheses(n, open, close-1, ans, output);
            output.pop_back();
        }
    }
        
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        vector<string> ans;
        int open = n;
        int close = n;
        string output = "";
        generateParantheses(n, open, close, ans, output);
        return ans;
    }